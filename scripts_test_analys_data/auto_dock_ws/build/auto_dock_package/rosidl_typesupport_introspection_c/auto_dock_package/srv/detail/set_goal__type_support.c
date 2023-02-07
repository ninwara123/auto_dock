// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from auto_dock_package:srv/SetGoal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "auto_dock_package/srv/detail/set_goal__rosidl_typesupport_introspection_c.h"
#include "auto_dock_package/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "auto_dock_package/srv/detail/set_goal__functions.h"
#include "auto_dock_package/srv/detail/set_goal__struct.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  auto_dock_package__srv__SetGoal_Request__init(message_memory);
}

void SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_fini_function(void * message_memory)
{
  auto_dock_package__srv__SetGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_member_array[1] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auto_dock_package__srv__SetGoal_Request, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_members = {
  "auto_dock_package__srv",  // message namespace
  "SetGoal_Request",  // message name
  1,  // number of fields
  sizeof(auto_dock_package__srv__SetGoal_Request),
  SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_member_array,  // message members
  SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_type_support_handle = {
  0,
  &SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auto_dock_package
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auto_dock_package, srv, SetGoal_Request)() {
  SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_type_support_handle.typesupport_identifier) {
    SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SetGoal_Request__rosidl_typesupport_introspection_c__SetGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "auto_dock_package/srv/detail/set_goal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "auto_dock_package/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "auto_dock_package/srv/detail/set_goal__functions.h"
// already included above
// #include "auto_dock_package/srv/detail/set_goal__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  auto_dock_package__srv__SetGoal_Response__init(message_memory);
}

void SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_fini_function(void * message_memory)
{
  auto_dock_package__srv__SetGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auto_dock_package__srv__SetGoal_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_message_members = {
  "auto_dock_package__srv",  // message namespace
  "SetGoal_Response",  // message name
  1,  // number of fields
  sizeof(auto_dock_package__srv__SetGoal_Response),
  SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_message_member_array,  // message members
  SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_message_type_support_handle = {
  0,
  &SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auto_dock_package
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auto_dock_package, srv, SetGoal_Response)() {
  if (!SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_message_type_support_handle.typesupport_identifier) {
    SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SetGoal_Response__rosidl_typesupport_introspection_c__SetGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "auto_dock_package/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "auto_dock_package/srv/detail/set_goal__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_service_members = {
  "auto_dock_package__srv",  // service namespace
  "SetGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_Request_message_type_support_handle,
  NULL  // response message
  // auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_service_type_support_handle = {
  0,
  &auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auto_dock_package, srv, SetGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auto_dock_package, srv, SetGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auto_dock_package
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auto_dock_package, srv, SetGoal)() {
  if (!auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_service_type_support_handle.typesupport_identifier) {
    auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auto_dock_package, srv, SetGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auto_dock_package, srv, SetGoal_Response)()->data;
  }

  return &auto_dock_package__srv__detail__set_goal__rosidl_typesupport_introspection_c__SetGoal_service_type_support_handle;
}
