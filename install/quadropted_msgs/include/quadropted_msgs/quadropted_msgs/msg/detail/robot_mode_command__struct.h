// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from quadropted_msgs:msg/RobotModeCommand.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__STRUCT_H_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RobotModeCommand in the package quadropted_msgs.
/**
  * RobotModeCommand.msg
  * Описание режима работы робота
 */
typedef struct quadropted_msgs__msg__RobotModeCommand
{
  /// Возможные режимы работы
  /// Режим работы: REST, TROT, CRAWL, STAND, etc.
  rosidl_runtime_c__String mode;
  /// Опционально: Добавление дополнительных параметров
  /// Идентификатор робота (если используется несколько роботов)
  uint16_t robot_id;
} quadropted_msgs__msg__RobotModeCommand;

// Struct for a sequence of quadropted_msgs__msg__RobotModeCommand.
typedef struct quadropted_msgs__msg__RobotModeCommand__Sequence
{
  quadropted_msgs__msg__RobotModeCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} quadropted_msgs__msg__RobotModeCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_MODE_COMMAND__STRUCT_H_
