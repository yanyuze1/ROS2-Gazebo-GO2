import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # -------------------------- 1. 声明启动参数 --------------------------
    pkg_share = FindPackageShare(package='cartographer').find('cartographer')
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    rviz_config_dir = os.path.join(pkg_share, 'rviz')+"/go2_cartographer.rviz"
    namespace_arg = DeclareLaunchArgument(
        'namespace',
        default_value='robot1',
        description='Robot namespace'
    )

    # -------------------------- 2. 获取slam_toolbox默认配置文件 --------------------------
    slam_toolbox_share = FindPackageShare('slam_toolbox')
    default_params_file = PathJoinSubstitution(
        [slam_toolbox_share, 'config', 'mapper_params_online_async.yaml']
    )

    # -------------------------- 3. 配置slam_toolbox节点 --------------------------
    slam_toolbox_node = Node(
        package='slam_toolbox',        
        executable='async_slam_toolbox_node',  
        name='slam_toolbox',        
        namespace=LaunchConfiguration('namespace'),  
        output='screen',               
        parameters=[
            use_sim_time,
            default_params_file,
            {
                'scan_topic': 'velodyne',    
                'odom_topic': 'odom',    
                'base_frame': 'base_link', 
                'odom_frame': 'odom',            
            }
        ],
        remappings=[
            ('/tf', 'tf'),
            ('/tf_static', 'tf_static')
        ]
    )
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_dir],
        parameters=[{'use_sim_time': use_sim_time}],
        output='screen',
        remappings=[
            ('/tf', '/robot1/tf'),
            ('/tf_static', '/robot1/tf_static')
        ])
    # -------------------------- 4. 组装并返回LaunchDescription --------------------------
    return LaunchDescription([
        namespace_arg,
        slam_toolbox_node,
        rviz_node
    ])
