import os
import yaml

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    LogInfo
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # ───── Set up paths and environment ────────────────────────────────────────
    go2_nav_dir = get_package_share_directory('navigation2')
    robot_config_path = os.path.join(go2_nav_dir, 'config', 'robots.yaml')
    rviz_template_path = os.path.join(go2_nav_dir, 'rviz', 'go2_nav2.rviz')
    default_map_path = os.path.join(go2_nav_dir, 'maps', 'warehouse_map.yaml')

    param_file_name = f"go2_nav2.yaml"
    param_file_path = os.path.join(go2_nav_dir, 'param', param_file_name)

    # ───── Launch arguments ────────────────────────────────────────────────────
    declare_map_arg = DeclareLaunchArgument(
        'map',
        default_value=default_map_path,
        description='Full path to the map file to load.'
    )

    declare_params_arg = DeclareLaunchArgument(
        'params_file',
        default_value=param_file_path,
        description='Full path to the navigation parameter file.'
    )

    declare_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true.'
    )

    # Create main launch description
    ld = LaunchDescription()
    ld.add_action(declare_map_arg)
    ld.add_action(declare_params_arg)
    ld.add_action(declare_sim_time_arg)

    # Load robot configurations
    with open(robot_config_path, 'r') as f:
        robots = [r for r in yaml.safe_load(f)['robots'] if r.get('enabled', True)]

    use_sim_time = LaunchConfiguration('use_sim_time')
    map_path = LaunchConfiguration('map')
    params_path = LaunchConfiguration('params_file')

    # Per-robot bringup
    for robot in robots:
        robot_name = robot['name']
        namespace = f'/{robot_name}'

        rviz_config =  rviz_template_path

        ld.add_action(LogInfo(msg=['[Launch] Using param file: ', params_path]))

        nav2_launch = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(
                    get_package_share_directory('nav2_bringup'),
                    'launch',
                    'bringup_launch.py'
                )
            ),
            launch_arguments={
                'map': map_path,
                'use_sim_time': use_sim_time,
                'params_file': params_path,
                'use_namespace': 'true',
                'namespace': robot_name
            }.items()
        )

        rviz_node = Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            namespace=namespace,
            arguments=['-d', rviz_config],
            parameters=[{'use_sim_time': use_sim_time, 'log_level': 'warn'}],
            remappings=[
                ('/tf', f'tf'),
                ('/tf_static', f'tf_static')
            ],
            output='screen'
        )

        ld.add_action(nav2_launch)
        ld.add_action(rviz_node)

    return ld