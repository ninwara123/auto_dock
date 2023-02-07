// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auto_dock_package:srv/SetGoal.idl
// generated code does not contain a copyright notice
#include "auto_dock_package/srv/detail/set_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
auto_dock_package__srv__SetGoal_Request__init(auto_dock_package__srv__SetGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    auto_dock_package__srv__SetGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
auto_dock_package__srv__SetGoal_Request__fini(auto_dock_package__srv__SetGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
}

bool
auto_dock_package__srv__SetGoal_Request__are_equal(const auto_dock_package__srv__SetGoal_Request * lhs, const auto_dock_package__srv__SetGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  return true;
}

bool
auto_dock_package__srv__SetGoal_Request__copy(
  const auto_dock_package__srv__SetGoal_Request * input,
  auto_dock_package__srv__SetGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  return true;
}

auto_dock_package__srv__SetGoal_Request *
auto_dock_package__srv__SetGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_dock_package__srv__SetGoal_Request * msg = (auto_dock_package__srv__SetGoal_Request *)allocator.allocate(sizeof(auto_dock_package__srv__SetGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auto_dock_package__srv__SetGoal_Request));
  bool success = auto_dock_package__srv__SetGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auto_dock_package__srv__SetGoal_Request__destroy(auto_dock_package__srv__SetGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auto_dock_package__srv__SetGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auto_dock_package__srv__SetGoal_Request__Sequence__init(auto_dock_package__srv__SetGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_dock_package__srv__SetGoal_Request * data = NULL;

  if (size) {
    data = (auto_dock_package__srv__SetGoal_Request *)allocator.zero_allocate(size, sizeof(auto_dock_package__srv__SetGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auto_dock_package__srv__SetGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auto_dock_package__srv__SetGoal_Request__fini(&data[i - 1]);
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
auto_dock_package__srv__SetGoal_Request__Sequence__fini(auto_dock_package__srv__SetGoal_Request__Sequence * array)
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
      auto_dock_package__srv__SetGoal_Request__fini(&array->data[i]);
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

auto_dock_package__srv__SetGoal_Request__Sequence *
auto_dock_package__srv__SetGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_dock_package__srv__SetGoal_Request__Sequence * array = (auto_dock_package__srv__SetGoal_Request__Sequence *)allocator.allocate(sizeof(auto_dock_package__srv__SetGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auto_dock_package__srv__SetGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auto_dock_package__srv__SetGoal_Request__Sequence__destroy(auto_dock_package__srv__SetGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auto_dock_package__srv__SetGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auto_dock_package__srv__SetGoal_Request__Sequence__are_equal(const auto_dock_package__srv__SetGoal_Request__Sequence * lhs, const auto_dock_package__srv__SetGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auto_dock_package__srv__SetGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auto_dock_package__srv__SetGoal_Request__Sequence__copy(
  const auto_dock_package__srv__SetGoal_Request__Sequence * input,
  auto_dock_package__srv__SetGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auto_dock_package__srv__SetGoal_Request);
    auto_dock_package__srv__SetGoal_Request * data =
      (auto_dock_package__srv__SetGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auto_dock_package__srv__SetGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          auto_dock_package__srv__SetGoal_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auto_dock_package__srv__SetGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
auto_dock_package__srv__SetGoal_Response__init(auto_dock_package__srv__SetGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
auto_dock_package__srv__SetGoal_Response__fini(auto_dock_package__srv__SetGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
auto_dock_package__srv__SetGoal_Response__are_equal(const auto_dock_package__srv__SetGoal_Response * lhs, const auto_dock_package__srv__SetGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
auto_dock_package__srv__SetGoal_Response__copy(
  const auto_dock_package__srv__SetGoal_Response * input,
  auto_dock_package__srv__SetGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

auto_dock_package__srv__SetGoal_Response *
auto_dock_package__srv__SetGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_dock_package__srv__SetGoal_Response * msg = (auto_dock_package__srv__SetGoal_Response *)allocator.allocate(sizeof(auto_dock_package__srv__SetGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auto_dock_package__srv__SetGoal_Response));
  bool success = auto_dock_package__srv__SetGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auto_dock_package__srv__SetGoal_Response__destroy(auto_dock_package__srv__SetGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auto_dock_package__srv__SetGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auto_dock_package__srv__SetGoal_Response__Sequence__init(auto_dock_package__srv__SetGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_dock_package__srv__SetGoal_Response * data = NULL;

  if (size) {
    data = (auto_dock_package__srv__SetGoal_Response *)allocator.zero_allocate(size, sizeof(auto_dock_package__srv__SetGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auto_dock_package__srv__SetGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auto_dock_package__srv__SetGoal_Response__fini(&data[i - 1]);
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
auto_dock_package__srv__SetGoal_Response__Sequence__fini(auto_dock_package__srv__SetGoal_Response__Sequence * array)
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
      auto_dock_package__srv__SetGoal_Response__fini(&array->data[i]);
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

auto_dock_package__srv__SetGoal_Response__Sequence *
auto_dock_package__srv__SetGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auto_dock_package__srv__SetGoal_Response__Sequence * array = (auto_dock_package__srv__SetGoal_Response__Sequence *)allocator.allocate(sizeof(auto_dock_package__srv__SetGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auto_dock_package__srv__SetGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auto_dock_package__srv__SetGoal_Response__Sequence__destroy(auto_dock_package__srv__SetGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auto_dock_package__srv__SetGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auto_dock_package__srv__SetGoal_Response__Sequence__are_equal(const auto_dock_package__srv__SetGoal_Response__Sequence * lhs, const auto_dock_package__srv__SetGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auto_dock_package__srv__SetGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auto_dock_package__srv__SetGoal_Response__Sequence__copy(
  const auto_dock_package__srv__SetGoal_Response__Sequence * input,
  auto_dock_package__srv__SetGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auto_dock_package__srv__SetGoal_Response);
    auto_dock_package__srv__SetGoal_Response * data =
      (auto_dock_package__srv__SetGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auto_dock_package__srv__SetGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          auto_dock_package__srv__SetGoal_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auto_dock_package__srv__SetGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
