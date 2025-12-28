// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from quadropted_msgs:msg/RobotFootContact.idl
// generated code does not contain a copyright notice
#include "quadropted_msgs/msg/detail/robot_foot_contact__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "quadropted_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "quadropted_msgs/msg/detail/robot_foot_contact__struct.h"
#include "quadropted_msgs/msg/detail/robot_foot_contact__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RobotFootContact__ros_msg_type = quadropted_msgs__msg__RobotFootContact;

static bool _RobotFootContact__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotFootContact__ros_msg_type * ros_message = static_cast<const _RobotFootContact__ros_msg_type *>(untyped_ros_message);
  // Field name: contacts
  {
    size_t size = 4;
    auto array_ptr = ros_message->contacts;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _RobotFootContact__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotFootContact__ros_msg_type * ros_message = static_cast<_RobotFootContact__ros_msg_type *>(untyped_ros_message);
  // Field name: contacts
  {
    size_t size = 4;
    auto array_ptr = ros_message->contacts;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_quadropted_msgs
size_t get_serialized_size_quadropted_msgs__msg__RobotFootContact(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotFootContact__ros_msg_type * ros_message = static_cast<const _RobotFootContact__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name contacts
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->contacts;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RobotFootContact__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_quadropted_msgs__msg__RobotFootContact(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_quadropted_msgs
size_t max_serialized_size_quadropted_msgs__msg__RobotFootContact(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: contacts
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = quadropted_msgs__msg__RobotFootContact;
    is_plain =
      (
      offsetof(DataType, contacts) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RobotFootContact__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_quadropted_msgs__msg__RobotFootContact(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotFootContact = {
  "quadropted_msgs::msg",
  "RobotFootContact",
  _RobotFootContact__cdr_serialize,
  _RobotFootContact__cdr_deserialize,
  _RobotFootContact__get_serialized_size,
  _RobotFootContact__max_serialized_size
};

static rosidl_message_type_support_t _RobotFootContact__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotFootContact,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, quadropted_msgs, msg, RobotFootContact)() {
  return &_RobotFootContact__type_support;
}

#if defined(__cplusplus)
}
#endif
