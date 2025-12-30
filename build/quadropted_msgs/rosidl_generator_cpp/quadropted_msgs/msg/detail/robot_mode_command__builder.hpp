// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadropted_msgs:msg/RobotModeCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__BUILDER_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadropted_msgs/msg/detail/robot_mode_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadropted_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotModeCommand_robot_id
{
public:
  explicit Init_RobotModeCommand_robot_id(::quadropted_msgs::msg::RobotModeCommand & msg)
  : msg_(msg)
  {}
  ::quadropted_msgs::msg::RobotModeCommand robot_id(::quadropted_msgs::msg::RobotModeCommand::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotModeCommand msg_;
};

class Init_RobotModeCommand_mode
{
public:
  Init_RobotModeCommand_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotModeCommand_robot_id mode(::quadropted_msgs::msg::RobotModeCommand::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_RobotModeCommand_robot_id(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotModeCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadropted_msgs::msg::RobotModeCommand>()
{
  return quadropted_msgs::msg::builder::Init_RobotModeCommand_mode();
}

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__BUILDER_HPP_
