// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from quadropted_msgs:msg/RobotModeCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__TRAITS_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "quadropted_msgs/msg/detail/robot_mode_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace quadropted_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotModeCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotModeCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotModeCommand & msg, bool use_flow_style = false)
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
  const quadropted_msgs::msg::RobotModeCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadropted_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadropted_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const quadropted_msgs::msg::RobotModeCommand & msg)
{
  return quadropted_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<quadropted_msgs::msg::RobotModeCommand>()
{
  return "quadropted_msgs::msg::RobotModeCommand";
}

template<>
inline const char * name<quadropted_msgs::msg::RobotModeCommand>()
{
  return "quadropted_msgs/msg/RobotModeCommand";
}

template<>
struct has_fixed_size<quadropted_msgs::msg::RobotModeCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<quadropted_msgs::msg::RobotModeCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<quadropted_msgs::msg::RobotModeCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__TRAITS_HPP_
