#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, TransformStamped
from std_msgs.msg import Int64
from rosgraph_msgs.msg import Clock
from builtin_interfaces.msg import Time
import tf_transformations
import tf2_ros
import math
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy
from quadropted_msgs.msg import RobotVelocity, RobotFootContact
from ForwardKinematics import robot_FK
from std_msgs.msg import Float64MultiArray
from visualization_msgs.msg import Marker, MarkerArray
from collections import deque

class DogOdometry(Node):
    def __init__(self):
        super().__init__('dog_odometry')

        # Параметры узла
        self.declare_parameter('verbose', False)
        self.verbose = self.get_parameter('verbose').get_parameter_value().bool_value
        if self.verbose:
            self.get_logger().info(f"Verbose mode: {self.verbose}")

        self.declare_parameter('publish_rate', 50)
        publish_rate = self.get_parameter('publish_rate').get_parameter_value().integer_value
        if self.verbose:
            self.get_logger().info(f"Publish rate: {publish_rate} Hz")

        self.declare_parameter('has_imu_heading', True)
        self.has_imu_heading = self.get_parameter('has_imu_heading').get_parameter_value().bool_value
        if self.verbose:
            self.get_logger().info(f"Has IMU heading: {self.has_imu_heading}")

        self.declare_parameter('enable_odom_tf', True)
        self.enable_odom_tf = self.get_parameter('enable_odom_tf').get_parameter_value().bool_value
        if self.verbose:
            self.get_logger().info(f"Enable odom TF: {self.enable_odom_tf}")

        self.declare_parameter('base_frame_id', 'base')
        self.base_frame_id = self.get_parameter('base_frame_id').get_parameter_value().string_value
        if self.verbose:
            self.get_logger().info(f"Base frame ID: {self.base_frame_id}")

        self.declare_parameter('odom_frame_id', 'odom')
        self.odom_frame_id = self.get_parameter('odom_frame_id').get_parameter_value().string_value
        if self.verbose:
            self.get_logger().info(f"Odom frame ID: {self.odom_frame_id}")

        self.declare_parameter('is_gazebo', True)
        self.is_gazebo = self.get_parameter('is_gazebo').get_parameter_value().bool_value
        if self.verbose:
            self.get_logger().info(f"Is Gazebo: {self.is_gazebo}")

        self.declare_parameter('clock_topic', '/clock')
        clock_topic = self.get_parameter('clock_topic').get_parameter_value().string_value
        if self.verbose:
            self.get_logger().info(f"Clock Topic: {clock_topic}")

        # Инициализация переменных одометрии
        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0
        self.linear_velocity_x = 0.0
        self.linear_velocity_y = 0.0
        self.angular_velocity = 0.0
        # Параметры фильтра скользящего среднего
        self.filter_window_size = 14  # OKNOIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO~~~~!!!!!!!!!!!!
        self.delta_x_queue = deque(maxlen=self.filter_window_size)
        self.delta_y_queue = deque(maxlen=self.filter_window_size)
        
        self.last_position_time = self.get_clock().now()

        self.gazebo_clock = Time()
        self.encoder_pos = 0

        # Коэффициент для коррекции скорости (может потребоваться калибровка)
        self.VELOCITY_COEFFICIENT = 11.66

        # Размеры тела и ног (может потребоваться корректировка)
        body_dimensions = [0.3762, 0.0935]  # [длина, ширина]
        leg_dimensions = [0.0, 0.0955, 0.213, 0.213]  # [l1, l2, l3, l4]

        # Инициализация Forward Kinematics
        self.fk_solver = robot_FK.ForwardKinematics(body_dimensions, leg_dimensions)

        # QoS профили
        qos_reliable = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=10,
            history=HistoryPolicy.KEEP_LAST
        )
        qos_best_effort = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            depth=10,
            history=HistoryPolicy.KEEP_LAST
        )

        # Паблишер одометрии
        self.odom_pub = self.create_publisher(Odometry, 'odom', qos_reliable)

        # Подписки
        if self.has_imu_heading:
            self.imu_sub = self.create_subscription(
                Imu,
                'imu_plugin/out',
                self.imu_callback,
                qos_reliable
            )

        self.velocity_sub = self.create_subscription(
            RobotVelocity,
            'robot_velocity',
            self.velocity_callback,
            qos_reliable
        )

        self.joint_states_sub = self.create_subscription(
            Float64MultiArray,
            'joint_group_controller/commands',
            self.joint_states_callback,
            qos_reliable
        )

        self.foot_contacts_sub = self.create_subscription(
            RobotFootContact,
            'foot_contact',  # Убедитесь, что это правильный топик
            self.foot_contacts_callback,
            qos_best_effort
        )

        # Трансформ-бродкастер
        if self.enable_odom_tf:
            self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)

        # Подписка на clock или encoder_value
        if self.is_gazebo:
            clock_qos = QoSProfile(
                reliability=ReliabilityPolicy.RELIABLE,
                durability=DurabilityPolicy.VOLATILE,
                depth=10,
                history=HistoryPolicy.KEEP_LAST
            )
            self.clock_sub = self.create_subscription(
                Clock,
                clock_topic,
                self.clock_callback,
                clock_qos
            )
            if self.verbose:
                self.get_logger().info("Subscribed to /clock topic with RELIABLE QoS.")
        else:
            encoder_qos = QoSProfile(
                reliability=ReliabilityPolicy.BEST_EFFORT,
                durability=DurabilityPolicy.VOLATILE,
                depth=10,
                history=HistoryPolicy.KEEP_LAST
            )
            self.encoder_sub = self.create_subscription(
                Int64,
                'encoder_value',
                self.encoder_callback,
                encoder_qos
            )
            if self.verbose:
                self.get_logger().info("Subscribed to encoder_value topic with BEST_EFFORT QoS.")

        # Паблишер маркеров для визуализации лап
        self.marker_pub = self.create_publisher(MarkerArray, 'foot_markers', qos_reliable)

        # Инициализация предыдущих позиций лап
        self.prev_foot_positions = [None, None, None, None]

        # Таймер для обновления одометрии
        timer_period = 1.0 / publish_rate
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.get_logger().info("Dog Odometry Node has been started.")

        self.MAX_LINEAR_VELOCITY_X = 0.035
        self.MAX_LINEAR_VELOCITY_Y = 0.012
        self.MAX_ANGULAR_VELOCITY = 1.0

        self.imu_angular_velocity = 0.0

        # Переменные для контактов лап и суставов
        self.foot_contacts = [False, False, False, False]  # [FR, FL, RR, RL]
        self.joint_positions = [0.0] * 12  # 3 угла на каждую ногу (4 ноги * 3 угла)
        self.foot_positions = [(0.0, 0.0, 0.0)] * 4  # Позиции лап [FR, FL, RR, RL]

    def velocity_callback(self, msg):
        # Предполагается, что msg.cmd_vel.linear.x уже масштабирован корректно
        self.linear_velocity_x = msg.cmd_vel.linear.x
        self.linear_velocity_y = msg.cmd_vel.linear.y
        if self.verbose:
            self.get_logger().info(
                f"Robot Velocity - Linear X: {self.linear_velocity_x:.6f} m/s, "
                f"Linear Y: {self.linear_velocity_y:.6f} m/s"
            )

    def joint_states_callback(self, msg):
        # Предполагается, что имена суставов в порядке FR_hip_joint, FR_thigh_joint, FR_calf_joint, ...
        if len(msg.data) != 12:
            self.get_logger().error(f"Unexpected number of joint angles: {len(msg.data)}. Expected 12.")
            return
        self.joint_positions = list(msg.data)
        if self.verbose:
            self.get_logger().info(f"Joint Positions: {self.joint_positions}")

    def foot_contacts_callback(self, msg):
        if self.verbose:
            self.get_logger().info(f"Received foot_contacts message: {msg}")

        # Проверка длины списка contacts
        if len(msg.contacts) != 4:
            self.get_logger().error(f"Unexpected number of contacts: {len(msg.contacts)}. Expected 4.")
            self.foot_contacts = [False, False, False, False]
            return

        self.foot_contacts = list(msg.contacts)
        if self.verbose:
            self.get_logger().info(f"Foot Contacts: {self.foot_contacts}")

    def imu_callback(self, msg):
        orientation_q = msg.orientation
        orientation_list = [orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
        (roll, pitch, yaw) = tf_transformations.euler_from_quaternion(orientation_list)

        self.theta = yaw  # Устанавливаем theta только из IMU
        self.imu_angular_velocity = -msg.angular_velocity.z

        if self.verbose:
            self.get_logger().info(f"IMU Yaw: {self.theta:.6f} rad")
            self.get_logger().info(f"IMU Angular Velocity: {self.imu_angular_velocity:.6f} rad/s")

    def clock_callback(self, msg):
        self.gazebo_clock = msg.clock
        if self.verbose:
            self.get_logger().info(f"Received Gazebo Clock: {self.gazebo_clock.sec}.{self.gazebo_clock.nanosec}")

    def encoder_callback(self, msg):
        self.encoder_pos = msg.data
        if self.verbose:
            self.get_logger().info(f"Received Encoder Position: {self.encoder_pos}")

    def normalize_angle(self, angle):
        """
        Нормализует угол до диапазона [-pi, pi].
        :param angle: Угол в радианах.
        :return: Нормализованный угол.
        """
        return math.atan2(math.sin(angle), math.cos(angle))

    def calculate_foot_positions(self):
        """
        Вычисляет позиции всех лап на основе текущих углов суставов.
        """
        # Список углов суставов: [FR_hip, FR_thigh, FR_calf, FL_hip, FL_thigh, FL_calf,
        #                           RR_hip, RR_thigh, RR_calf, RL_hip, RL_thigh, RL_calf]
        if len(self.joint_positions) != 12:
            self.get_logger().error(f"Incorrect number of joint positions: {len(self.joint_positions)}. Expected 12.")
            return

        try:
            foot_positions = self.fk_solver.forward_kinematics_all_legs(self.joint_positions)
            self.foot_positions = foot_positions
        except Exception as e:
            self.get_logger().error(f"Error in forward kinematics: {e}")
            self.foot_positions = [(0.0, 0.0, 0.0)] * 4
            return

        if self.verbose:
            for i, pos in enumerate(self.foot_positions):
                leg = ['FR', 'FL', 'RR', 'RL'][i]
                self.get_logger().info(f"{leg} Foot Position: x={pos[0]:.4f}, y={pos[1]:.4f}, z={pos[2]:.4f}")

    def update_odometry(self):
        current_time = self.get_clock().now()
        dt = (current_time - self.last_position_time).nanoseconds / 1e9
        if dt <= 0.0:
            return

        if self.verbose:
            self.get_logger().info(f"Foot contacts during update_odometry: {self.foot_contacts}")

        delta_x_total, delta_y_total = 0.0, 0.0
        contact_count = 0

        for i in range(4):  # Для каждой лапы
            if self.foot_contacts[i]:  # Если лапа на земле
                # Используем позицию лапы относительно base_link
                foot_rel_x, foot_rel_y = self.foot_positions[i][0], self.foot_positions[i][1]

                if self.prev_foot_positions[i] is not None:
                    delta_x = foot_rel_x - self.prev_foot_positions[i][0]
                    delta_y = foot_rel_y - self.prev_foot_positions[i][1]

                    # Смещение робота является противоположным изменению позиций лап
                    delta_x_total += delta_x
                    delta_y_total += -delta_y
                    contact_count += 0.65

                    if self.verbose:
                        leg = ['FR', 'FL', 'RR', 'RL'][i]
                        self.get_logger().info(f"{leg} foot movement: Δx={delta_x:.6f}, Δy={delta_y:.6f}")
                else:
                    # Если это первая запись, просто сохраните текущие позиции лап
                    if self.verbose:
                        leg = ['FR', 'FL', 'RR', 'RL'][i]
                        self.get_logger().info(f"{leg} foot first contact position: x={foot_rel_x:.6f}, y={foot_rel_y:.6f}")

                # Обновляем предыдущие позиции лап
                self.prev_foot_positions[i] = (foot_rel_x, foot_rel_y)

        if contact_count > 0:
            # Усредняем смещения
            delta_x = delta_x_total / contact_count
            delta_y = delta_y_total / contact_count

            # Добавляем смещения в очереди
            self.delta_x_queue.append(delta_x)
            self.delta_y_queue.append(delta_y)

            # Вычисляем среднее значение смещений
            avg_delta_x = sum(self.delta_x_queue) / len(self.delta_x_queue)
            avg_delta_y = sum(self.delta_y_queue) / len(self.delta_y_queue)

            # Обновляем позицию робота с учётом ориентации
            self.x += (avg_delta_x * math.cos(self.theta) - avg_delta_y * math.sin(self.theta))
            self.y += (avg_delta_x * math.sin(self.theta) + avg_delta_y * math.cos(self.theta))

            if self.verbose:
                self.get_logger().info(f"Odometry updated based on foot contacts: Δx={avg_delta_x:.6f}, Δy={avg_delta_y:.6f}")
        else:
            # Если ни одна лапа не на земле, обновляем одометрию на основе команд скорости
            delta_x = self.linear_velocity_x * dt
            delta_y = self.linear_velocity_y * dt

            # Добавляем смещения в очереди
            self.delta_x_queue.append(delta_x)
            self.delta_y_queue.append(delta_y)

            # Вычисляем среднее значение смещений
            avg_delta_x = sum(self.delta_x_queue) / len(self.delta_x_queue)
            avg_delta_y = sum(self.delta_y_queue) / len(self.delta_y_queue)

            self.x += (avg_delta_x * math.cos(self.theta) - avg_delta_y * math.sin(self.theta))
            self.y += (avg_delta_x * math.sin(self.theta) + avg_delta_y * math.cos(self.theta))

            if self.verbose:
                self.get_logger().info(f"No feet in contact. Odometry updated based on velocity commands: Δx={avg_delta_x:.6f}, Δy={avg_delta_y:.6f}")

        # Не обновляем theta здесь, оно устанавливается только из IMU
        self.last_position_time = current_time

    def publish_odometry(self):
        odom = Odometry()
        if self.is_gazebo:
            odom.header.stamp = self.gazebo_clock
        else:
            odom.header.stamp = self.get_clock().now().to_msg()
        odom.header.frame_id = self.odom_frame_id
        odom.child_frame_id = self.base_frame_id

        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.position.z = 0.0

        quaternion = tf_transformations.quaternion_from_euler(0, 0, self.theta)
        odom.pose.pose.orientation = Quaternion(
            x=quaternion[0],
            y=quaternion[1],
            z=quaternion[2],
            w=quaternion[3]
        )

        # Обновление twist.twist на основе команд скорости
        odom.twist.twist.linear.x = self.linear_velocity_x
        odom.twist.twist.linear.y = self.linear_velocity_y
        odom.twist.twist.angular.z = self.imu_angular_velocity  # Устанавливаем угловую скорость на основе IMU

        self.odom_pub.publish(odom)

        if self.enable_odom_tf:
            t = TransformStamped()
            if self.is_gazebo:
                t.header.stamp = self.gazebo_clock
            else:
                t.header.stamp = self.get_clock().now().to_msg()
            t.header.frame_id = self.odom_frame_id
            t.child_frame_id = self.base_frame_id

            t.transform.translation.x = self.x
            t.transform.translation.y = self.y
            t.transform.translation.z = 0.0
            t.transform.rotation = Quaternion(
                x=quaternion[0],
                y=quaternion[1],
                z=quaternion[2],
                w=quaternion[3]
            )

            self.tf_broadcaster.sendTransform(t)

    def publish_markers(self):
        marker_array = MarkerArray()
        for i, pos in enumerate(self.foot_positions):
            marker = Marker()
            marker.header.frame_id = self.base_frame_id
            marker.header.stamp = self.get_clock().now().to_msg()
            marker.ns = "foot_markers"
            marker.id = i
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD
            marker.pose.position.x = pos[0]
            marker.pose.position.y = pos[1]
            marker.pose.position.z = pos[2]
            marker.pose.orientation.x = 0.0
            marker.pose.orientation.y = 0.0
            marker.pose.orientation.z = 0.0
            marker.pose.orientation.w = 1.0
            marker.scale.x = 0.05
            marker.scale.y = 0.05
            marker.scale.z = 0.05
            marker.color.a = 1.0
            marker.color.r = 1.0
            marker.color.g = 0.0
            marker.color.b = 0.0
            marker_array.markers.append(marker)
        self.marker_pub.publish(marker_array)

    def timer_callback(self):
        # Расчет позиций лап
        self.calculate_foot_positions()

        # Обновление одометрии на основе позиций лап и контактов
        self.update_odometry()

        # Публикация одометрии
        self.publish_odometry()

        # Публикация маркеров
        self.publish_markers()

        if self.verbose:
            self.get_logger().info(f"Position Updated: x={self.x:.6f} m, y={self.y:.6f} m, theta={self.theta:.6f} rad")

def main(args=None):
    rclpy.init(args=args)
    try:
        node = DogOdometry()
    except Exception as e:
        print(f"Exception during node initialization: {e}")
        rclpy.shutdown()
        return
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
