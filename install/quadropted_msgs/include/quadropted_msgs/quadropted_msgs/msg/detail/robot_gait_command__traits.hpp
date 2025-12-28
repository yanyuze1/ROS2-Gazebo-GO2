// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from quadropted_msgs:msg/RobotGaitCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__TRAITS_HPP_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "quadropted_msgs/msg/detail/robot_gait_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace quadropted_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotGaitCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: gait_type
  {
    out << "gait_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gait_type, out);
    out << ", ";
  }

  // member: body_height
  {
    out << "body_height: ";
    rosidl_generator_traits::value_to_yaml(msg.body_height, out);
    out << ", ";
  }

  // member: leg_height
  {
    out << "leg_height: ";
    rosidl_generator_traits::value_to_yaml(msg.leg_height, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotGaitCommand & msg,
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

  // member: gait_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gait_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gait_type, out);
    out << "\n";
  }

  // member: body_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_height: ";
    rosidl_generator_traits::value_to_yaml(msg.body_height, out);
    out << "\n";
  }

  // member: leg_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "leg_height: ";
    rosidl_generator_traits::value_to_yaml(msg.leg_height, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotGaitCommand & msg, bool use_flow_style = false)
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
  const quadropted_msgs::msg::RobotGaitCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadropted_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadropted_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const quadropted_msgs::msg::RobotGaitCommand & msg)
{
  return quadropted_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<quadropted_msgs::msg::RobotGaitCommand>()
{
  return "quadropted_msgs::msg::RobotGaitCommand";
}

template<>
inline const char * name<quadropted_msgs::msg::RobotGaitCommand>()
{
  return "quadropted_msgs/msg/RobotGaitCommand";
}

template<>
struct has_fixed_size<quadropted_msgs::msg::RobotGaitCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<quadropted_msgs::msg::RobotGaitCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<quadropted_msgs::msg::RobotGaitCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__TRAITS_HPP_
