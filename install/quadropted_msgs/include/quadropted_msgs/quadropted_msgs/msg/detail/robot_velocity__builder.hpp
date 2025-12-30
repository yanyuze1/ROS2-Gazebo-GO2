// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadropted_msgs:msg/RobotVelocity.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__BUILDER_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadropted_msgs/msg/detail/robot_velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadropted_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotVelocity_cmd_vel
{
public:
  explicit Init_RobotVelocity_cmd_vel(::quadropted_msgs::msg::RobotVelocity & msg)
  : msg_(msg)
  {}
  ::quadropted_msgs::msg::RobotVelocity cmd_vel(::quadropted_msgs::msg::RobotVelocity::_cmd_vel_type arg)
  {
    msg_.cmd_vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotVelocity msg_;
};

class Init_RobotVelocity_robot_id
{
public:
  Init_RobotVelocity_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotVelocity_cmd_vel robot_id(::quadropted_msgs::msg::RobotVelocity::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotVelocity_cmd_vel(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotVelocity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadropted_msgs::msg::RobotVelocity>()
{
  return quadropted_msgs::msg::builder::Init_RobotVelocity_robot_id();
}

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__BUILDER_HPP_
