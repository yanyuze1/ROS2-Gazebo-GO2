// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from quadropted_msgs:msg/RobotFootContact.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__BUILDER_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "quadropted_msgs/msg/detail/robot_foot_contact__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace quadropted_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotFootContact_contacts
{
public:
  Init_RobotFootContact_contacts()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::quadropted_msgs::msg::RobotFootContact contacts(::quadropted_msgs::msg::RobotFootContact::_contacts_type arg)
  {
    msg_.contacts = std::move(arg);
    return std::move(msg_);
  }

private:
  ::quadropted_msgs::msg::RobotFootContact msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::quadropted_msgs::msg::RobotFootContact>()
{
  return quadropted_msgs::msg::builder::Init_RobotFootContact_contacts();
}

}  // namespace quadropted_msgs

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__BUILDER_HPP_
