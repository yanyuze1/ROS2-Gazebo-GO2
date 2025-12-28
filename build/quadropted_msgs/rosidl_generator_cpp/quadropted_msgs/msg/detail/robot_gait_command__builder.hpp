// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadropted_msgs:msg/RobotGaitCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__BUILDER_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadropted_msgs/msg/detail/robot_gait_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadropted_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotGaitCommand_leg_height
{
public:
  explicit Init_RobotGaitCommand_leg_height(::quadropted_msgs::msg::RobotGaitCommand & msg)
  : msg_(msg)
  {}
  ::quadropted_msgs::msg::RobotGaitCommand leg_height(::quadropted_msgs::msg::RobotGaitCommand::_leg_height_type arg)
  {
    msg_.leg_height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotGaitCommand msg_;
};

class Init_RobotGaitCommand_body_height
{
public:
  explicit Init_RobotGaitCommand_body_height(::quadropted_msgs::msg::RobotGaitCommand & msg)
  : msg_(msg)
  {}
  Init_RobotGaitCommand_leg_height body_height(::quadropted_msgs::msg::RobotGaitCommand::_body_height_type arg)
  {
    msg_.body_height = std::move(arg);
    return Init_RobotGaitCommand_leg_height(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotGaitCommand msg_;
};

class Init_RobotGaitCommand_gait_type
{
public:
  explicit Init_RobotGaitCommand_gait_type(::quadropted_msgs::msg::RobotGaitCommand & msg)
  : msg_(msg)
  {}
  Init_RobotGaitCommand_body_height gait_type(::quadropted_msgs::msg::RobotGaitCommand::_gait_type_type arg)
  {
    msg_.gait_type = std::move(arg);
    return Init_RobotGaitCommand_body_height(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotGaitCommand msg_;
};

class Init_RobotGaitCommand_robot_id
{
public:
  Init_RobotGaitCommand_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotGaitCommand_gait_type robot_id(::quadropted_msgs::msg::RobotGaitCommand::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotGaitCommand_gait_type(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotGaitCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadropted_msgs::msg::RobotGaitCommand>()
{
  return quadropted_msgs::msg::builder::Init_RobotGaitCommand_robot_id();
}

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__BUILDER_HPP_
