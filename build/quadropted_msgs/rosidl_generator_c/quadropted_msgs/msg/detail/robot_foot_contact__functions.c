// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from quadropted_msgs:msg/RobotFootContact.idl
// generated code does not contain a copyright notice
#include "quadropted_msgs/msg/detail/robot_foot_contact__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
quadropted_msgs__msg__RobotFootContact__init(quadropted_msgs__msg__RobotFootContact * msg)
{
  if (!msg) {
    return false;
  }
  // contacts
  return true;
}

void
quadropted_msgs__msg__RobotFootContact__fini(quadropted_msgs__msg__RobotFootContact * msg)
{
  if (!msg) {
    return;
  }
  // contacts
}

bool
quadropted_msgs__msg__RobotFootContact__are_equal(const quadropted_msgs__msg__RobotFootContact * lhs, const quadropted_msgs__msg__RobotFootContact * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // contacts
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->contacts[i] != rhs->contacts[i]) {
      return false;
    }
  }
  return true;
}

bool
quadropted_msgs__msg__RobotFootContact__copy(
  const quadropted_msgs__msg__RobotFootContact * input,
  quadropted_msgs__msg__RobotFootContact * output)
{
  if (!input || !output) {
    return false;
  }
  // contacts
  for (size_t i = 0; i < 4; ++i) {
    output->contacts[i] = input->contacts[i];
  }
  return true;
}

quadropted_msgs__msg__RobotFootContact *
quadropted_msgs__msg__RobotFootContact__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadropted_msgs__msg__RobotFootContact * msg = (quadropted_msgs__msg__RobotFootContact *)allocator.allocate(sizeof(quadropted_msgs__msg__RobotFootContact), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(quadropted_msgs__msg__RobotFootContact));
  bool success = quadropted_msgs__msg__RobotFootContact__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
quadropted_msgs__msg__RobotFootContact__destroy(quadropted_msgs__msg__RobotFootContact * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    quadropted_msgs__msg__RobotFootContact__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
quadropted_msgs__msg__RobotFootContact__Sequence__init(quadropted_msgs__msg__RobotFootContact__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadropted_msgs__msg__RobotFootContact * data = NULL;

  if (size) {
    data = (quadropted_msgs__msg__RobotFootContact *)allocator.zero_allocate(size, sizeof(quadropted_msgs__msg__RobotFootContact), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = quadropted_msgs__msg__RobotFootContact__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        quadropted_msgs__msg__RobotFootContact__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
quadropted_msgs__msg__RobotFootContact__Sequence__fini(quadropted_msgs__msg__RobotFootContact__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      quadropted_msgs__msg__RobotFootContact__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

quadropted_msgs__msg__RobotFootContact__Sequence *
quadropted_msgs__msg__RobotFootContact__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  quadropted_msgs__msg__RobotFootContact__Sequence * array = (quadropted_msgs__msg__RobotFootContact__Sequence *)allocator.allocate(sizeof(quadropted_msgs__msg__RobotFootContact__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = quadropted_msgs__msg__RobotFootContact__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
quadropted_msgs__msg__RobotFootContact__Sequence__destroy(quadropted_msgs__msg__RobotFootContact__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    quadropted_msgs__msg__RobotFootContact__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
quadropted_msgs__msg__RobotFootContact__Sequence__are_equal(const quadropted_msgs__msg__RobotFootContact__Sequence * lhs, const quadropted_msgs__msg__RobotFootContact__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!quadropted_msgs__msg__RobotFootContact__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
quadropted_msgs__msg__RobotFootContact__Sequence__copy(
  const quadropted_msgs__msg__RobotFootContact__Sequence * input,
  quadropted_msgs__msg__RobotFootContact__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(quadropted_msgs__msg__RobotFootContact);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    quadropted_msgs__msg__RobotFootContact * data =
      (quadropted_msgs__msg__RobotFootContact *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!quadropted_msgs__msg__RobotFootContact__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          quadropted_msgs__msg__RobotFootContact__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!quadropted_msgs__msg__RobotFootContact__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
