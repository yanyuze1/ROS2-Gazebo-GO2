// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from quadropted_msgs:msg/RobotVelocity.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "quadropted_msgs/msg/detail/robot_velocity__rosidl_typesupport_introspection_c.h"
#include "quadropted_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "quadropted_msgs/msg/detail/robot_velocity__functions.h"
#include "quadropted_msgs/msg/detail/robot_velocity__struct.h"


// Include directives for member types
// Member `cmd_vel`
#include "geometry_msgs/msg/twist.h"
// Member `cmd_vel`
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  quadropted_msgs__msg__RobotVelocity__init(message_memory);
}

void quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_fini_function(void * message_memory)
{
  quadropted_msgs__msg__RobotVelocity__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_member_array[2] = {
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(quadropted_msgs__msg__RobotVelocity, robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cmd_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(quadropted_msgs__msg__RobotVelocity, cmd_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_members = {
  "quadropted_msgs__msg",  // message namespace
  "RobotVelocity",  // message name
  2,  // number of fields
  sizeof(quadropted_msgs__msg__RobotVelocity),
  quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_member_array,  // message members
  quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_init_function,  // function to initialize message memory (memory has to be allocated)
  quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_type_support_handle = {
  0,
  &quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_quadropted_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, quadropted_msgs, msg, RobotVelocity)() {
  quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Twist)();
  if (!quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_type_support_handle.typesupport_identifier) {
    quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &quadropted_msgs__msg__RobotVelocity__rosidl_typesupport_introspection_c__RobotVelocity_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
