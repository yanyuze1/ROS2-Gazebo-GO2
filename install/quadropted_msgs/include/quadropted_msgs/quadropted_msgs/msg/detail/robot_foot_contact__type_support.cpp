// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from quadropted_msgs:msg/RobotFootContact.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "quadropted_msgs/msg/detail/robot_foot_contact__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace quadropted_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotFootContact_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) quadropted_msgs::msg::RobotFootContact(_init);
}

void RobotFootContact_fini_function(void * message_memory)
{
  auto typed_message = static_cast<quadropted_msgs::msg::RobotFootContact *>(message_memory);
  typed_message->~RobotFootContact();
}

size_t size_function__RobotFootContact__contacts(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__RobotFootContact__contacts(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotFootContact__contacts(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__RobotFootContact__contacts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__RobotFootContact__contacts(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__RobotFootContact__contacts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__RobotFootContact__contacts(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotFootContact_message_member_array[1] = {
  {
    "contacts",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(quadropted_msgs::msg::RobotFootContact, contacts),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotFootContact__contacts,  // size() function pointer
    get_const_function__RobotFootContact__contacts,  // get_const(index) function pointer
    get_function__RobotFootContact__contacts,  // get(index) function pointer
    fetch_function__RobotFootContact__contacts,  // fetch(index, &value) function pointer
    assign_function__RobotFootContact__contacts,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotFootContact_message_members = {
  "quadropted_msgs::msg",  // message namespace
  "RobotFootContact",  // message name
  1,  // number of fields
  sizeof(quadropted_msgs::msg::RobotFootContact),
  RobotFootContact_message_member_array,  // message members
  RobotFootContact_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotFootContact_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotFootContact_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotFootContact_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace quadropted_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<quadropted_msgs::msg::RobotFootContact>()
{
  return &::quadropted_msgs::msg::rosidl_typesupport_introspection_cpp::RobotFootContact_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, quadropted_msgs, msg, RobotFootContact)() {
  return &::quadropted_msgs::msg::rosidl_typesupport_introspection_cpp::RobotFootContact_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
