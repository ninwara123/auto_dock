// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from my_first_package:srv/RandGoal.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "my_first_package/msg/rosidl_typesupport_c__visibility_control.h"
#include "my_first_package/srv/detail/rand_goal__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace my_first_package
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _RandGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RandGoal_Request_type_support_ids_t;

static const _RandGoal_Request_type_support_ids_t _RandGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _RandGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RandGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RandGoal_Request_type_support_symbol_names_t _RandGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_first_package, srv, RandGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package, srv, RandGoal_Request)),
  }
};

typedef struct _RandGoal_Request_type_support_data_t
{
  void * data[2];
} _RandGoal_Request_type_support_data_t;

static _RandGoal_Request_type_support_data_t _RandGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RandGoal_Request_message_typesupport_map = {
  2,
  "my_first_package",
  &_RandGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_RandGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_RandGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RandGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RandGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace my_first_package

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_my_first_package
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_first_package, srv, RandGoal_Request)() {
  return &::my_first_package::srv::rosidl_typesupport_c::RandGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_first_package/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "my_first_package/srv/detail/rand_goal__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_first_package
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _RandGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RandGoal_Response_type_support_ids_t;

static const _RandGoal_Response_type_support_ids_t _RandGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _RandGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RandGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RandGoal_Response_type_support_symbol_names_t _RandGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_first_package, srv, RandGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package, srv, RandGoal_Response)),
  }
};

typedef struct _RandGoal_Response_type_support_data_t
{
  void * data[2];
} _RandGoal_Response_type_support_data_t;

static _RandGoal_Response_type_support_data_t _RandGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RandGoal_Response_message_typesupport_map = {
  2,
  "my_first_package",
  &_RandGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_RandGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_RandGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RandGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RandGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace my_first_package

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_my_first_package
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_first_package, srv, RandGoal_Response)() {
  return &::my_first_package::srv::rosidl_typesupport_c::RandGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "my_first_package/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_first_package
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _RandGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RandGoal_type_support_ids_t;

static const _RandGoal_type_support_ids_t _RandGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _RandGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RandGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RandGoal_type_support_symbol_names_t _RandGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_first_package, srv, RandGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package, srv, RandGoal)),
  }
};

typedef struct _RandGoal_type_support_data_t
{
  void * data[2];
} _RandGoal_type_support_data_t;

static _RandGoal_type_support_data_t _RandGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RandGoal_service_typesupport_map = {
  2,
  "my_first_package",
  &_RandGoal_service_typesupport_ids.typesupport_identifier[0],
  &_RandGoal_service_typesupport_symbol_names.symbol_name[0],
  &_RandGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t RandGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RandGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace my_first_package

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_my_first_package
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, my_first_package, srv, RandGoal)() {
  return &::my_first_package::srv::rosidl_typesupport_c::RandGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
