// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadropted_msgs:msg/RobotFootContact.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__STRUCT_H_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RobotFootContact in the package quadropted_msgs.
/**
  * RobotFootContact.msg
 */
typedef struct quadropted_msgs__msg__RobotFootContact
{
  /// [FR, FL, RR, RL]
  bool contacts[4];
} quadropted_msgs__msg__RobotFootContact;

// Struct for a sequence of quadropted_msgs__msg__RobotFootContact.
typedef struct quadropted_msgs__msg__RobotFootContact__Sequence
{
  quadropted_msgs__msg__RobotFootContact * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadropted_msgs__msg__RobotFootContact__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_FOOT_CONTACT__STRUCT_H_
