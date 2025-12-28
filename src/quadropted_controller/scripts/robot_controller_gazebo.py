#!/usr/bin/env python3
# Author: lnotspotl, abutalipovvv
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray  
from quadropted_msgs.msg import RobotModeCommand, RobotVelocity  
from quadropted_msgs.srv import RobotBehaviorCommand
from InverseKinematics import robot_IK
from RobotController import RobotController
import numpy as np  

USE_IMU = True
RATE = 60

class RobotControllerNode(Node):
    def __init__(self):
        super().__init__("Robot_Controller")

        # Объявляем параметры
        self.declare_parameter('verbose', False)
        self.verbose = self.get_parameter('verbose').get_parameter_value().bool_value
        if self.verbose:
            self.get_logger().info(f"Verbose mode: {self.verbose}")

        # Геометрия робота
        body = [0.3762, 0.0935]
        legs = [0.0, 0.0955, 0.213, 0.213]
        
        self.declare_parameter('robot_id', 1)
        self.robot_id = self.get_parameter('robot_id').get_parameter_value().integer_value

        
        self.robot = RobotController.Robot(self, body, legs, USE_IMU, self.robot_id)
        self.inverseKinematics = robot_IK.InverseKinematics(body, legs)

        
        self.joint_command_publisher = self.create_publisher(Float64MultiArray, "joint_group_controller/commands", 10)

        
        self.create_subscription(RobotModeCommand, "robot_mode", self.robot.mode_callback, 10)
        self.create_subscription(RobotVelocity, "robot_velocity", self.robot.velocity_callback, 10)

        
        self.timer = self.create_timer(1.0 / RATE, self.control_loop)

    def control_loop(self):
        if self.verbose:
            self.get_logger().info("Control loop triggered")
        
        leg_positions = self.robot.run()
        
        
        self.robot.change_controller()

        dx = self.robot.state.body_local_position[0]
        dy = self.robot.state.body_local_position[1]
        dz = self.robot.state.body_local_position[2]

        roll = self.robot.state.body_local_orientation[0]
        pitch = self.robot.state.body_local_orientation[1]
        yaw = self.robot.state.body_local_orientation[2]

        try:
            
            joint_angles = self.inverseKinematics.inverse_kinematics(leg_positions, dx, dy, dz, roll, pitch, yaw)

            
            joint_command_msg = Float64MultiArray()
            joint_command_msg.data = joint_angles  
            self.joint_command_publisher.publish(joint_command_msg)
            if self.verbose:
                self.get_logger().info(f"Published joint angles: {joint_angles}")

        except Exception as e:
            self.get_logger().error(f"Error in control loop: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = RobotControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
