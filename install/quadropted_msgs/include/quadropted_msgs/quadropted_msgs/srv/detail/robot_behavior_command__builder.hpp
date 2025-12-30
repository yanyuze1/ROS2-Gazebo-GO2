// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadropted_msgs:srv/RobotBehaviorCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__BUILDER_HPP_
#define QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadropted_msgs/srv/detail/robot_behavior_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadropted_msgs
{

namespace srv
{

namespace builder
{

class Init_RobotBehaviorCommand_Request_command
{
public:
  Init_RobotBehaviorCommand_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::quadropted_msgs::srv::RobotBehaviorCommand_Request command(::quadropted_msgs::srv::RobotBehaviorCommand_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadropted_msgs::srv::RobotBehaviorCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadropted_msgs::srv::RobotBehaviorCommand_Request>()
{
  return quadropted_msgs::srv::builder::Init_RobotBehaviorCommand_Request_command();
}

}  // namespace quadropted_msgs


namespace quadropted_msgs
{

namespace srv
{

namespace builder
{

class Init_RobotBehaviorCommand_Response_message
{
public:
  explicit Init_RobotBehaviorCommand_Response_message(::quadropted_msgs::srv::RobotBehaviorCommand_Response & msg)
  : msg_(msg)
  {}
  ::quadropted_msgs::srv::RobotBehaviorCommand_Response message(::quadropted_msgs::srv::RobotBehaviorCommand_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadropted_msgs::srv::RobotBehaviorCommand_Response msg_;
};

class Init_RobotBehaviorCommand_Response_success
{
public:
  Init_RobotBehaviorCommand_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotBehaviorCommand_Response_message success(::quadropted_msgs::srv::RobotBehaviorCommand_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_RobotBehaviorCommand_Response_message(msg_);
  }

private:
  ::quadropted_msgs::srv::RobotBehaviorCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadropted_msgs::srv::RobotBehaviorCommand_Response>()
{
  return quadropted_msgs::srv::builder::Init_RobotBehaviorCommand_Response_success();
}

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__BUILDER_HPP_
