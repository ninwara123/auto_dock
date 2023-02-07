// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auto_dock_package:srv/SetGoal.idl
// generated code does not contain a copyright notice

#ifndef AUTO_DOCK_PACKAGE__SRV__DETAIL__SET_GOAL__STRUCT_H_
#define AUTO_DOCK_PACKAGE__SRV__DETAIL__SET_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in srv/SetGoal in the package auto_dock_package.
typedef struct auto_dock_package__srv__SetGoal_Request
{
  geometry_msgs__msg__Point position;
} auto_dock_package__srv__SetGoal_Request;

// Struct for a sequence of auto_dock_package__srv__SetGoal_Request.
typedef struct auto_dock_package__srv__SetGoal_Request__Sequence
{
  auto_dock_package__srv__SetGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auto_dock_package__srv__SetGoal_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SetGoal in the package auto_dock_package.
typedef struct auto_dock_package__srv__SetGoal_Response
{
  uint8_t structure_needs_at_least_one_member;
} auto_dock_package__srv__SetGoal_Response;

// Struct for a sequence of auto_dock_package__srv__SetGoal_Response.
typedef struct auto_dock_package__srv__SetGoal_Response__Sequence
{
  auto_dock_package__srv__SetGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auto_dock_package__srv__SetGoal_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTO_DOCK_PACKAGE__SRV__DETAIL__SET_GOAL__STRUCT_H_
