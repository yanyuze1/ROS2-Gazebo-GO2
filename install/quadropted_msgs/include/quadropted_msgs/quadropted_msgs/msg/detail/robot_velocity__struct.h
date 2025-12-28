// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadropted_msgs:msg/RobotVelocity.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__STRUCT_H_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cmd_vel'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/RobotVelocity in the package quadropted_msgs.
/**
  * RobotVelocity.msg
 */
typedef struct quadropted_msgs__msg__RobotVelocity
{
  uint16_t robot_id;
  geometry_msgs__msg__Twist cmd_vel;
} quadropted_msgs__msg__RobotVelocity;

// Struct for a sequence of quadropted_msgs__msg__RobotVelocity.
typedef struct quadropted_msgs__msg__RobotVelocity__Sequence
{
  quadropted_msgs__msg__RobotVelocity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadropted_msgs__msg__RobotVelocity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__STRUCT_H_
