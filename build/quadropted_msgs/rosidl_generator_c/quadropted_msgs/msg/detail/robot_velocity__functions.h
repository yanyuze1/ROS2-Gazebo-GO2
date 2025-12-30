// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from quadropted_msgs:msg/RobotVelocity.idl
// generated code does not contain a copyright notice

#ifndef QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__FUNCTIONS_H_
#define QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "quadropted_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "quadropted_msgs/msg/detail/robot_velocity__struct.h"

/// Initialize msg/RobotVelocity message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * quadropted_msgs__msg__RobotVelocity
 * )) before or use
 * quadropted_msgs__msg__RobotVelocity__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
bool
quadropted_msgs__msg__RobotVelocity__init(quadropted_msgs__msg__RobotVelocity * msg);

/// Finalize msg/RobotVelocity message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
void
quadropted_msgs__msg__RobotVelocity__fini(quadropted_msgs__msg__RobotVelocity * msg);

/// Create msg/RobotVelocity message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * quadropted_msgs__msg__RobotVelocity__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
quadropted_msgs__msg__RobotVelocity *
quadropted_msgs__msg__RobotVelocity__create();

/// Destroy msg/RobotVelocity message.
/**
 * It calls
 * quadropted_msgs__msg__RobotVelocity__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
void
quadropted_msgs__msg__RobotVelocity__destroy(quadropted_msgs__msg__RobotVelocity * msg);

/// Check for msg/RobotVelocity message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
bool
quadropted_msgs__msg__RobotVelocity__are_equal(const quadropted_msgs__msg__RobotVelocity * lhs, const quadropted_msgs__msg__RobotVelocity * rhs);

/// Copy a msg/RobotVelocity message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
bool
quadropted_msgs__msg__RobotVelocity__copy(
  const quadropted_msgs__msg__RobotVelocity * input,
  quadropted_msgs__msg__RobotVelocity * output);

/// Initialize array of msg/RobotVelocity messages.
/**
 * It allocates the memory for the number of elements and calls
 * quadropted_msgs__msg__RobotVelocity__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
bool
quadropted_msgs__msg__RobotVelocity__Sequence__init(quadropted_msgs__msg__RobotVelocity__Sequence * array, size_t size);

/// Finalize array of msg/RobotVelocity messages.
/**
 * It calls
 * quadropted_msgs__msg__RobotVelocity__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
void
quadropted_msgs__msg__RobotVelocity__Sequence__fini(quadropted_msgs__msg__RobotVelocity__Sequence * array);

/// Create array of msg/RobotVelocity messages.
/**
 * It allocates the memory for the array and calls
 * quadropted_msgs__msg__RobotVelocity__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
quadropted_msgs__msg__RobotVelocity__Sequence *
quadropted_msgs__msg__RobotVelocity__Sequence__create(size_t size);

/// Destroy array of msg/RobotVelocity messages.
/**
 * It calls
 * quadropted_msgs__msg__RobotVelocity__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
void
quadropted_msgs__msg__RobotVelocity__Sequence__destroy(quadropted_msgs__msg__RobotVelocity__Sequence * array);

/// Check for msg/RobotVelocity message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
bool
quadropted_msgs__msg__RobotVelocity__Sequence__are_equal(const quadropted_msgs__msg__RobotVelocity__Sequence * lhs, const quadropted_msgs__msg__RobotVelocity__Sequence * rhs);

/// Copy an array of msg/RobotVelocity messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_quadropted_msgs
bool
quadropted_msgs__msg__RobotVelocity__Sequence__copy(
  const quadropted_msgs__msg__RobotVelocity__Sequence * input,
  quadropted_msgs__msg__RobotVelocity__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // QUADROPTED_MSGS__MSG__DETAIL__ROBOT_VELOCITY__FUNCTIONS_H_
