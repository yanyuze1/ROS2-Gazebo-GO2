// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadropted_msgs:msg/RobotGaitCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__STRUCT_H_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'GAIT_TYPE_IDLE'.
/**
  * RobotGaitConstants.msg
 */
enum
{
  quadropted_msgs__msg__RobotGaitCommand__GAIT_TYPE_IDLE = 0
};

/// Constant 'GAIT_TYPE_TROT'.
enum
{
  quadropted_msgs__msg__RobotGaitCommand__GAIT_TYPE_TROT = 1
};

/// Constant 'GAIT_TYPE_TROT_RUN'.
enum
{
  quadropted_msgs__msg__RobotGaitCommand__GAIT_TYPE_TROT_RUN = 2
};

/// Constant 'GAIT_TYPE_CLIMB_STAIR'.
enum
{
  quadropted_msgs__msg__RobotGaitCommand__GAIT_TYPE_CLIMB_STAIR = 3
};

/// Constant 'GAIT_TYPE_TROT_OBST'.
enum
{
  quadropted_msgs__msg__RobotGaitCommand__GAIT_TYPE_TROT_OBST = 4
};

/// Struct defined in msg/RobotGaitCommand in the package quadropted_msgs.
/**
  * RobotGaitCommand.msg
  * ID робота
 */
typedef struct quadropted_msgs__msg__RobotGaitCommand
{
  uint16_t robot_id;
  /// Тип походки
  uint16_t gait_type;
  /// Высота корпуса
  float body_height;
  /// Высота шага
  float leg_height;
} quadropted_msgs__msg__RobotGaitCommand;

// Struct for a sequence of quadropted_msgs__msg__RobotGaitCommand.
typedef struct quadropted_msgs__msg__RobotGaitCommand__Sequence
{
  quadropted_msgs__msg__RobotGaitCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadropted_msgs__msg__RobotGaitCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_GAIT_COMMAND__STRUCT_H_
