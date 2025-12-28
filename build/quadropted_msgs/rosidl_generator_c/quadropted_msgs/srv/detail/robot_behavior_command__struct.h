// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadropted_msgs:srv/RobotBehaviorCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__STRUCT_H_
#define QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RobotBehaviorCommand in the package quadropted_msgs.
typedef struct quadropted_msgs__srv__RobotBehaviorCommand_Request
{
  rosidl_runtime_c__String command;
} quadropted_msgs__srv__RobotBehaviorCommand_Request;

// Struct for a sequence of quadropted_msgs__srv__RobotBehaviorCommand_Request.
typedef struct quadropted_msgs__srv__RobotBehaviorCommand_Request__Sequence
{
  quadropted_msgs__srv__RobotBehaviorCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadropted_msgs__srv__RobotBehaviorCommand_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RobotBehaviorCommand in the package quadropted_msgs.
typedef struct quadropted_msgs__srv__RobotBehaviorCommand_Response
{
  bool success;
  rosidl_runtime_c__String message;
} quadropted_msgs__srv__RobotBehaviorCommand_Response;

// Struct for a sequence of quadropted_msgs__srv__RobotBehaviorCommand_Response.
typedef struct quadropted_msgs__srv__RobotBehaviorCommand_Response__Sequence
{
  quadropted_msgs__srv__RobotBehaviorCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadropted_msgs__srv__RobotBehaviorCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADROPTED_MSGS__SRV__DETAIL__ROBOT_BEHAVIOR_COMMAND__STRUCT_H_
