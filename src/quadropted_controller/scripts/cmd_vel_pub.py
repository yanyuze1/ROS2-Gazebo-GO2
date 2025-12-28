#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from quadropted_msgs.msg import RobotVelocity
import math

class RobotVelocityHandler(Node):
    def __init__(self):
        super().__init__('robot_velocity_handler')

        self.declare_parameter('verbose', False)
        self.verbose = self.get_parameter('verbose').get_parameter_value().bool_value
        if self.verbose:
            self.get_logger().info(f"Verbose mode: {self.verbose}")

        self.subscription = self.create_subscription(
            Twist, 
            'cmd_vel',
            self.robot_velocity_callback, 
            10)

        self.publisher_ = self.create_publisher(RobotVelocity, 'robot_velocity', 10)
        if self.verbose:
            self.get_logger().info("Node started: RobotVelocityHandler")

        # Переменная для секундомера
        self.motion_start_time = None

    def robot_velocity_callback(self, msg: Twist):
        # Определяем, есть ли ненулевая скорость
        has_velocity = (msg.linear.x != 0 or msg.linear.y != 0 or 
                        msg.linear.z != 0 or 
                        msg.angular.x != 0 or msg.angular.y != 0 or msg.angular.z != 0)

        current_time = self.get_clock().now()

        # Если есть ненулевая скорость и секундомер не запущен — запускаем его
        if has_velocity and self.motion_start_time is None:
            self.motion_start_time = current_time
            if self.verbose:
                self.get_logger().info(f"Motion started at time: {current_time.to_msg()}")

        # Если скорости нет (робот остановился) и секундомер был запущен — останавливаем его
        if not has_velocity and self.motion_start_time is not None:
            elapsed = current_time - self.motion_start_time
            if self.verbose:
                self.get_logger().info(f"Motion stopped at time: {current_time.to_msg()}")
                self.get_logger().info(f"Elapsed motion time: {elapsed.nanoseconds / 1e9:.3f} seconds")
            self.motion_start_time = None
        if self.verbose:
            self.get_logger().info(
                f"Received Twist: linear=({msg.linear.x}, {msg.linear.y}, {msg.linear.z}), "
                f"angular=({msg.angular.x}, {msg.angular.y}, {msg.angular.z})"
            )

        new_msg = RobotVelocity()
        new_msg.robot_id = 1

        new_msg.cmd_vel.linear.x = self.multiply_and_limit(msg.linear.x, 0.035, -1.0, 1.0)
        new_msg.cmd_vel.linear.y = self.multiply_and_limit(msg.linear.y, 0.012, -1.0, 1.0)
        new_msg.cmd_vel.linear.z = msg.linear.z

        new_msg.cmd_vel.angular.x = msg.angular.x
        new_msg.cmd_vel.angular.y = msg.angular.y
        new_msg.cmd_vel.angular.z = self.limit(msg.angular.z, -1.0, 1.0)

        self.publisher_.publish(new_msg)
        if self.verbose:
            self.get_logger().info(
                f"Published RobotVelocity: robot_id={new_msg.robot_id}, "
                f"linear=({new_msg.cmd_vel.linear.x}, {new_msg.cmd_vel.linear.y}, {new_msg.cmd_vel.linear.z}), "
                f"angular=({new_msg.cmd_vel.angular.x}, {new_msg.cmd_vel.angular.y}, {new_msg.cmd_vel.angular.z})"
            )
        
    def multiply_and_limit(self, value, scale_factor, min_limit, max_limit):
        # Обработка положительных и отрицательных значений отдельно
        if value > 0:
            adjusted_value = value * 0.035
            scaled_value = scale_factor * (1 - math.exp(-100 * adjusted_value))
        else:
            # Для отрицательных значений значение умножаем на -0.035
            adjusted_value = (-value) * 0.035
            scaled_value = -scale_factor * (1 - math.exp(-100 * adjusted_value))
        
        return self.limit_value(scaled_value, min_limit, max_limit)

    def limit_value(self, value, min_limit, max_limit):
        if value > max_limit:
            return max_limit
        elif value < min_limit:
            return min_limit
        else:
            return value

    def limit(self, value, min_limit, max_limit):
        if value > max_limit:
            return max_limit
        elif value < min_limit:
            return min_limit
        else:
            return value

def main(args=None):
    rclpy.init(args=args)
    node = RobotVelocityHandler()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()