import os

from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

from launch_ros.actions import Node
import xacro


def generate_launch_description():

    package_name='go1_gazebo'
    namespace = '/robot1'
    name = 'robot1'

    # Process the URDF file
    pkg_path = os.path.join(get_package_share_directory(package_name))
    xacro_file = os.path.join(pkg_path,'xacro','robot.xacro')
    remappings = [
        ("/tf", "tf"),
        ("/tf_static", "tf_static"),
        ("/scan", "scan"),
        ("/odom", "odom")
    ]


    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    declare_use_sim_time = DeclareLaunchArgument(
        name='use_sim_time', default_value=use_sim_time, description='Использовать симуляционное время'
    )


    world = os.path.join(pkg_path, 'world', 'empty.world')    
    # Include the Gazebo launch file, provided by the ros_gz_sim package
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py')]),
                    launch_arguments={'gz_args': ['-r -v4 ', world], 'on_exit_shutdown': 'true'}.items()
             )

    # Run the spawner node from the ros_gz_sim package. The entity name doesn't really matter if you only have a single robot.
    spawn_entity = Node(package='ros_gz_sim', executable='create', namespace=namespace,
                        arguments=['-topic', f'{namespace}/robot_description',
                                   '-name', f'{namespace}/my_bot',
                                   '-z', '0.4'],
                        output='screen')



    robot_desc = xacro.process_file(
            xacro_file,
            mappings={'robot_name': name}
        ).toxml() 
    
    params = {'robot_description': robot_desc, 'use_sim_time': use_sim_time}

    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        namespace=namespace,
        parameters=[params],
        remappings=remappings
    )

    bridge_params = os.path.join(get_package_share_directory(package_name),'config','gz_bridge.yaml')
    ros_gz_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        namespace=namespace,
        arguments=[
            f"{namespace}/imu_plugin/out@sensor_msgs/msg/Imu@gz.msgs.IMU",
            f"{namespace}/scan@sensor_msgs/msg/LaserScan@gz.msgs.LaserScan",
            f"{namespace}/tf@tf2_msgs/msg/TFMessage@gz.msgs.Pose_V",
            f"{namespace}/joint_states@sensor_msgs/msg/JointState@gz.msgs.Model"
        ]
    )

    ros_gz_bridge_clock = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=[
            '--ros-args',
            '-p',
            f'config_file:={bridge_params}',
        ]
    )
        # Запуск контроллеров
    joint_state_broadcaster = Node(
        package="controller_manager",
        executable="spawner",
        namespace=namespace,
        arguments=["joint_state_broadcaster"],
        remappings=remappings

    )

    joint_group_controller = Node(
        package="controller_manager",
        executable="spawner",
        namespace=namespace,
        arguments=["joint_group_controller"],
        output="screen",
        remappings=remappings

    )

    # Ноды для управления роботом
    controller = Node(
        package='quadropted_controller',
        executable='robot_controller_gazebo.py',
        name='quadruped_controller',
        namespace=namespace,
        output='screen',
        remappings=remappings

    )


    cmd_vel_pub = Node(
        package='quadropted_controller',
        executable='cmd_vel_pub.py',
        name='cmd_vel_pub',
        namespace=namespace,
        output='screen',
    )

    odom =Node(
        package='quadropted_controller',
        executable='QuadrupedOdometryNode.py',
        name='odom',
        namespace=namespace,
        output='screen',
        parameters=[{
                "verbose": False,
                'publish_rate': 50,
                'open_loop': False,
                'has_imu_heading': True,
                'is_gazebo': True,
                'imu_topic': f"/{namespace}/imu",
                'base_frame_id': "base",
                'odom_frame_id': "odom",
                'clock_topic': '/clock',
                'enable_odom_tf': True,
        }],
        remappings=remappings
    )

    params_file = os.path.join(get_package_share_directory(package_name), 'config', 'nav2_params.yaml')
    map_dir = os.path.join(get_package_share_directory(package_name), 'maps', 'warehouse_map.yaml')

    bringup_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_path, 'launch', 'nav2', 'bringup_launch.py')),
        launch_arguments={
            'map': map_dir,
            'use_namespace': 'True',
            'namespace': namespace,
            'params_file': params_file,
            'autostart': 'true',
            'use_sim_time': 'True',
            'log_level': 'warn',
            'map_server': 'True'
        }.items()
    )

    rviz_config_file = os.path.join(pkg_path, 'config', 'multi_nav2_default_view.rviz')
    rviz = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(pkg_path, 'launch', "rviz_launch.py")),
            launch_arguments={
                "namespace": namespace,
                "use_namespace": 'true',
                "rviz_config": rviz_config_file,
            }.items()
        )

    # Launch them all!
    return LaunchDescription([
        declare_use_sim_time,
        node_robot_state_publisher,
        gazebo,
        spawn_entity,
        ros_gz_bridge,
        ros_gz_bridge_clock,
        joint_state_broadcaster,
        joint_group_controller,
        controller,
        cmd_vel_pub,
        odom,
        rviz,
        # bringup_cmd
    ])
