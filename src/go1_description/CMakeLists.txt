cmake_minimum_required(VERSION 3.8)
project(go1_description)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(urdf REQUIRED)
find_package(xacro REQUIRED)
find_package(std_msgs REQUIRED)

install(DIRECTORY
  meshes
  config
  xacro
  launch
  DESTINATION share/${PROJECT_NAME}/
)

install(PROGRAMS
  DESTINATION lib/${PROJECT_NAME}
)

install(
  PROGRAMS
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
