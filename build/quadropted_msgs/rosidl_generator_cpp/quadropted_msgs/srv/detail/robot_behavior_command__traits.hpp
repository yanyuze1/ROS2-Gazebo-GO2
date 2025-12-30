// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from quadropted_msgs:srv/RobotBehaviorCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__TRAITS_HPP_
#define QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "quadropted_msgs/srv/detail/robot_behavior_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace quadropted_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotBehaviorCommand_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotBehaviorCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotBehaviorCommand_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace quadropted_msgs

namespace rosidl_generator_traits
{

[[deprecated("use quadropted_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const quadropted_msgs::srv::RobotBehaviorCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadropted_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadropted_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const quadropted_msgs::srv::RobotBehaviorCommand_Request & msg)
{
  return quadropted_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<quadropted_msgs::srv::RobotBehaviorCommand_Request>()
{
  return "quadropted_msgs::srv::RobotBehaviorCommand_Request";
}

template<>
inline const char * name<quadropted_msgs::srv::RobotBehaviorCommand_Request>()
{
  return "quadropted_msgs/srv/RobotBehaviorCommand_Request";
}

template<>
struct has_fixed_size<quadropted_msgs::srv::RobotBehaviorCommand_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<quadropted_msgs::srv::RobotBehaviorCommand_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<quadropted_msgs::srv::RobotBehaviorCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace quadropted_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const RobotBehaviorCommand_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotBehaviorCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotBehaviorCommand_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace quadropted_msgs

namespace rosidl_generator_traits
{

[[deprecated("use quadropted_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const quadropted_msgs::srv::RobotBehaviorCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  quadropted_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use quadropted_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const quadropted_msgs::srv::RobotBehaviorCommand_Response & msg)
{
  return quadropted_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<quadropted_msgs::srv::RobotBehaviorCommand_Response>()
{
  return "quadropted_msgs::srv::RobotBehaviorCommand_Response";
}

template<>
inline const char * name<quadropted_msgs::srv::RobotBehaviorCommand_Response>()
{
  return "quadropted_msgs/srv/RobotBehaviorCommand_Response";
}

template<>
struct has_fixed_size<quadropted_msgs::srv::RobotBehaviorCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<quadropted_msgs::srv::RobotBehaviorCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<quadropted_msgs::srv::RobotBehaviorCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<quadropted_msgs::srv::RobotBehaviorCommand>()
{
  return "quadropted_msgs::srv::RobotBehaviorCommand";
}

template<>
inline const char * name<quadropted_msgs::srv::RobotBehaviorCommand>()
{
  return "quadropted_msgs/srv/RobotBehaviorCommand";
}

template<>
struct has_fixed_size<quadropted_msgs::srv::RobotBehaviorCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<quadropted_msgs::srv::RobotBehaviorCommand_Request>::value &&
    has_fixed_size<quadropted_msgs::srv::RobotBehaviorCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<quadropted_msgs::srv::RobotBehaviorCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<quadropted_msgs::srv::RobotBehaviorCommand_Request>::value &&
    has_bounded_size<quadropted_msgs::srv::RobotBehaviorCommand_Response>::value
  >
{
};

template<>
struct is_service<quadropted_msgs::srv::RobotBehaviorCommand>
  : std::true_type
{
};

template<>
struct is_service_request<quadropted_msgs::srv::RobotBehaviorCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<quadropted_msgs::srv::RobotBehaviorCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__TRAITS_HPP_
