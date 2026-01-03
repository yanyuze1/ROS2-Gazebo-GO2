FROM osrf/ros:humble-desktop-full

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y --no-install-recommends \
    build-essential \
    git \
    wget \
    ros-humble-controller-manager \
    ros-humble-hardware-interface \
    ros-humble-joint-state-publisher \
    ros-humble-slam-toolbox \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-rqt-robot-steering \
    ros-humble-rmw-cyclonedds-cpp \
    ros-humble-cyclonedds \
    ros-humble-velodyne-description \
    ros-humble-tf-transformations \
    ros-humble-opennav-docking \
    ros-humble-robot-localization \
    ros-humble-ros2-controllers \
    ros-humble-gazebo-ros \
    ros-humble-gazebo-plugins \
    ros-humble-gazebo-dev && \
    apt install -y --no-install-recommends \
    ros-humble-ros-ign \
    ros-humble-ign-ros2-control \
    ros-humble-gz-ros2-control && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

ENV DEBIAN_FRONTEND=

ARG USER_ID=1000
ARG GROUP_ID=1000

RUN groupadd -g ${GROUP_ID} rosuser && \
    useradd -u ${USER_ID} -g rosuser -m rosuser -s /bin/bash && \
    echo "rosuser ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

WORKDIR /home/ROS2/car/ROS2-Gazebo-GO2

RUN echo "source /opt/ros/humble/setup.bash" >> /home/rosuser/.bashrc && \
    echo "export GZ_SIM_RESOURCE_PATH=/home/ROS2/car/ROS2-Gazebo-GO2/src/gazebo_sim/models" >> /home/rosuser/.bashrc && \
    echo "export CYCLONEDDS_URI=file://home/ROS2/project/go2_sim_ws/src/docker/cyclonedds.xml" >> /home/rosuser/.bashrc

USER rosuser

CMD ["/bin/bash"]

