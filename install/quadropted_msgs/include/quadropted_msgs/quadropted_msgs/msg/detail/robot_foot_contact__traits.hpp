// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from quadropted_msgs:msg/RobotFootContact.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__TRAITS_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "quadropted_msgs/msg/detail/robot_foot_contact__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace quadropted_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotFootContact & msg,
  std::ostream & out)
{
  out << "{";
  // member: contacts
  {
    if (msg.contacts.size() == 0) {
      out << "contacts: []";
    } else {
      out << "contacts: [";
      size_t pending_items = msg.contacts.size();
      for (auto item : msg.contacts) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotFootContact & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: contacts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.contacts.size() == 0) {
      out << "contacts: []\n";
    } else {
      out << "contacts:\n";
      for (auto item : msg.contacts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotFootContact & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace quadropted_msgs

namespace rosidl_generator_traits
{

[[deprecated("use quadropted_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const quadropted_msgs::msg::RobotFootContact & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadropted_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadropted_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const quadropted_msgs::msg::RobotFootContact & msg)
{
  return quadropted_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<quadropted_msgs::msg::RobotFootContact>()
{
  return "quadropted_msgs::msg::RobotFootContact";
}

template<>
inline const char * name<quadropted_msgs::msg::RobotFootContact>()
{
  return "quadropted_msgs/msg/RobotFootContact";
}

template<>
struct has_fixed_size<quadropted_msgs::msg::RobotFootContact>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<quadropted_msgs::msg::RobotFootContact>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<quadropted_msgs::msg::RobotFootContact>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__TRAITS_HPP_
