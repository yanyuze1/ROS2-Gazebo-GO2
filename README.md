# 1. 项目描述
本项目为宇树机器狗系列第一章ROS2-Gazebo仿真的基础项目仓库，该仓库会随着系列项目的推进不定时进行更新，当前计划可查看本人飞书查看项目情况[项目情况](https://ai.feishu.cn/wiki/CVpbwLIiMiwGnekKjhMcLXTRnag?from=from_copylink)。
# 2. 项目使用
## 2.1 直接编译使用
进入到工作空间
```bash
cd go2_sim_ws
colcon build
soure install/setup.bash
export CYCLONEDDS_URI=file://~/go2_sim_ws/src/docker/cyclonedds.xml
```

![alt text](images/image-17.png)

启动，第一次启动会比较久，因为需要下载相应的场景资源。
```bash
ros2 launch gazebo_sim launch.py
```
成功启动后会如下图所示。
![alt text](images/image-18.png)

本项目配备了一个狗的前置普通单目摄像头用以模拟GO2本身的前置摄像头，同时配备了两个激光雷达，一个为模拟GO2的前置L1激光雷达，一个为模拟外界的VLP16激光雷达，两个激光雷达都可同时发布LaserScan类型数据和PointCloud2类型数据，为后续的建图和导航工作提供了便利，而后续也会更新加入D435i摄像头（已经加入D435i摄像头）。
```bash
cd go2_sim_ws
source install/local_setup.bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/robot1/cmd_vel
```
在终端中执行上述命令后就可以使用键盘对其进行简单的控制了，同时可以使用下面的服务完成对机器狗的控制,支持的服务有walk、up、sit，分别对应走、站、趴。
```bash
ros2 service call /robot1/robot_behavior_command quadropted_msgs/srv/RobotBehaviorCommand "{command: 'walk'}"
```
## 2.2 docker使用
在使用docker前请简单的阅读docker搭建流程指南，因为每个人的情况还是会有些许差别，而为我使用的是外挂卷的形式完成的任务。
使用下面的命令可以很快的帮您完成想要的操作。
```bash
cd go2_sim_ws/src/docker
docker compose up -d --build --remove-orphans        #容器构建
docker compose up -d go2_sim                        #启动容器，-d为不进入docker终端,ros2_sim是众多服务中的一个服务
docker compose ps                                    #容器查看
docker compose exec go2_sim bash                    #进入容器
docker compose down                                  #容器删除
```
进入到docker后，可以按照前面直接安装的操作来
```bash
colcon build
soure install/setup.bash
```
![alt text](images/image-19.png)

启动，第一次启动会比较久，因为需要下载相应的场景资源。
```bash
ros2 launch gazebo_sim launch.py
```
成功启动后会如下图所示。

![alt text](images/image-20.png)

本项目配备了一个狗的前置普通单目摄像头用以模拟GO2本身的前置摄像头，同时配备了两个激光雷达，一个为模拟GO2的前置L1激光雷达，一个为模拟外界的VLP16激光雷达，两个激光雷达都可同时发布LaserScan类型数据和PointCloud2类型数据，为后续的建图和导航工作提供了便利，而后续也会更新加入D435i摄像头。
```bash
cd go2_sim_ws
source install/local_setup.bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/robot1/cmd_vel
```
在终端中执行上述命令后就可以使用键盘对其进行简单的控制了，同时可以使用下面的服务完成对机器狗的控制,支持的服务有walk、up、sit，分别对应走、站、趴。
```bash
ros2 service call /robot1/robot_behavior_command quadropted_msgs/srv/RobotBehaviorCommand "{command: 'walk'}"
```
