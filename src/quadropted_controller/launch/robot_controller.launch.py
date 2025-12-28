# Modified for ros2 by: abutalipovvv
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='quadropted_controller',
            executable='robot_controller_gazebo.py',
            name='ROBOT_CONTROLLER',
            output='screen',
            parameters=[{
                'use_sim_time': True ,
            }]
        ),
    ])