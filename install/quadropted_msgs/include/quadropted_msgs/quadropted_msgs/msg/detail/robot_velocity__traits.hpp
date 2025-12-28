// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from quadropted_msgs:msg/RobotVelocity.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__TRAITS_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "quadropted_msgs/msg/detail/robot_velocity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'cmd_vel'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace quadropted_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotVelocity & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: cmd_vel
  {
    out << "cmd_vel: ";
    to_flow_style_yaml(msg.cmd_vel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotVelocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: cmd_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_vel:\n";
    to_block_style_yaml(msg.cmd_vel, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotVelocity & msg, bool use_flow_style = false)
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
  const quadropted_msgs::msg::RobotVelocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadropted_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadropted_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const quadropted_msgs::msg::RobotVelocity & msg)
{
  return quadropted_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<quadropted_msgs::msg::RobotVelocity>()
{
  return "quadropted_msgs::msg::RobotVelocity";
}

template<>
inline const char * name<quadropted_msgs::msg::RobotVelocity>()
{
  return "quadropted_msgs/msg/RobotVelocity";
}

template<>
struct has_fixed_size<quadropted_msgs::msg::RobotVelocity>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct has_bounded_size<quadropted_msgs::msg::RobotVelocity>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct is_message<quadropted_msgs::msg::RobotVelocity>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__TRAITS_HPP_
