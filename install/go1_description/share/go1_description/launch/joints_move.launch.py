import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, Command
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import LaunchConfiguration, Command, FindExecutable, PathJoinSubstitution

def generate_launch_description():
    # Paths to files and directories
    go1_description_pkg = get_package_share_directory('go1_gazebo')
    xacro_path = os.path.join(go1_description_pkg, 'urdf', 'go1.urdf.xacro')
    
    # Declare launch arguments
    user_debug_arg = DeclareLaunchArgument(
        'user_debug',
        default_value='false',
        description='Enable debug mode'
    )
    
    # Command to convert xacro to robot_description
    robot_description_content = Command([PathJoinSubstitution([FindExecutable(name="xacro")]), " ", xacro_path])
    robot_description = {"robot_description": robot_description_content}
    
    # Node to spawn joint state broadcaster
    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", "--controller-manager", "/controller_manager"],
        output="screen",
    )

    # Node to spawn joint group controller
    spawn_controller = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_group_controller", "--controller-manager", "/controller_manager"],
        output="screen",
    )

    # Node for controlling the robot
    controller = Node(
        package='quadropted_controller',
        executable='robot_controller_gazebo.py',
        name='quadruped_controller',
        output='screen',
    )

    # IMU bridge node
    imu_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        name="ign_imu",
        arguments=["/imu_plugin/out@sensor_msgs/msg/Imu@ignition.msgs.IMU"],
        output='screen',
    )

    # Command velocity publisher
    cmd_vel_pub = Node(
        package='quadropted_controller',
        executable='cmd_vel_pub.py',
        name='cmd_vel_pub',
        output='screen',
    )

    # Launch description
    return LaunchDescription([
        # Declare user_debug argument
        user_debug_arg,

        # Robot description (xacro with optional debug)
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            output="both",
            parameters=[robot_description],
        ),

        # Joint state publisher GUI
        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher_gui',
            parameters=[{'use_gui': True}],
            output='screen'
        ),

        # Rviz node
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            arguments=[
                '-d', os.path.join(go1_description_pkg, 'config', 'check_joint.rviz')
            ]
        ),

        # Controllers and other nodes
        spawn_controller,
        controller,
        imu_bridge,
        cmd_vel_pub,
        joint_state_broadcaster_spawner
    ])
