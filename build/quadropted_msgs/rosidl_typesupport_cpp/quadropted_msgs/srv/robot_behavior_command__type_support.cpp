// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from quadropted_msgs:srv/RobotBehaviorCommand.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "quadropted_msgs/srv/detail/robot_behavior_command__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace quadropted_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _RobotBehaviorCommand_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RobotBehaviorCommand_Request_type_support_ids_t;

static const _RobotBehaviorCommand_Request_type_support_ids_t _RobotBehaviorCommand_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _RobotBehaviorCommand_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RobotBehaviorCommand_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RobotBehaviorCommand_Request_type_support_symbol_names_t _RobotBehaviorCommand_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, quadropted_msgs, srv, RobotBehaviorCommand_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, quadropted_msgs, srv, RobotBehaviorCommand_Request)),
  }
};

typedef struct _RobotBehaviorCommand_Request_type_support_data_t
{
  void * data[2];
} _RobotBehaviorCommand_Request_type_support_data_t;

static _RobotBehaviorCommand_Request_type_support_data_t _RobotBehaviorCommand_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RobotBehaviorCommand_Request_message_typesupport_map = {
  2,
  "quadropted_msgs",
  &_RobotBehaviorCommand_Request_message_typesupport_ids.typesupport_identifier[0],
  &_RobotBehaviorCommand_Request_message_typesupport_symbol_names.symbol_name[0],
  &_RobotBehaviorCommand_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RobotBehaviorCommand_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RobotBehaviorCommand_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace quadropted_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<quadropted_msgs::srv::RobotBehaviorCommand_Request>()
{
  return &::quadropted_msgs::srv::rosidl_typesupport_cpp::RobotBehaviorCommand_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, quadropted_msgs, srv, RobotBehaviorCommand_Request)() {
  return get_message_type_support_handle<quadropted_msgs::srv::RobotBehaviorCommand_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "quadropted_msgs/srv/detail/robot_behavior_command__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace quadropted_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _RobotBehaviorCommand_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RobotBehaviorCommand_Response_type_support_ids_t;

static const _RobotBehaviorCommand_Response_type_support_ids_t _RobotBehaviorCommand_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _RobotBehaviorCommand_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RobotBehaviorCommand_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RobotBehaviorCommand_Response_type_support_symbol_names_t _RobotBehaviorCommand_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, quadropted_msgs, srv, RobotBehaviorCommand_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, quadropted_msgs, srv, RobotBehaviorCommand_Response)),
  }
};

typedef struct _RobotBehaviorCommand_Response_type_support_data_t
{
  void * data[2];
} _RobotBehaviorCommand_Response_type_support_data_t;

static _RobotBehaviorCommand_Response_type_support_data_t _RobotBehaviorCommand_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RobotBehaviorCommand_Response_message_typesupport_map = {
  2,
  "quadropted_msgs",
  &_RobotBehaviorCommand_Response_message_typesupport_ids.typesupport_identifier[0],
  &_RobotBehaviorCommand_Response_message_typesupport_symbol_names.symbol_name[0],
  &_RobotBehaviorCommand_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RobotBehaviorCommand_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RobotBehaviorCommand_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace quadropted_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<quadropted_msgs::srv::RobotBehaviorCommand_Response>()
{
  return &::quadropted_msgs::srv::rosidl_typesupport_cpp::RobotBehaviorCommand_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, quadropted_msgs, srv, RobotBehaviorCommand_Response)() {
  return get_message_type_support_handle<quadropted_msgs::srv::RobotBehaviorCommand_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "quadropted_msgs/srv/detail/robot_behavior_command__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace quadropted_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _RobotBehaviorCommand_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RobotBehaviorCommand_type_support_ids_t;

static const _RobotBehaviorCommand_type_support_ids_t _RobotBehaviorCommand_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _RobotBehaviorCommand_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RobotBehaviorCommand_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RobotBehaviorCommand_type_support_symbol_names_t _RobotBehaviorCommand_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, quadropted_msgs, srv, RobotBehaviorCommand)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, quadropted_msgs, srv, RobotBehaviorCommand)),
  }
};

typedef struct _RobotBehaviorCommand_type_support_data_t
{
  void * data[2];
} _RobotBehaviorCommand_type_support_data_t;

static _RobotBehaviorCommand_type_support_data_t _RobotBehaviorCommand_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RobotBehaviorCommand_service_typesupport_map = {
  2,
  "quadropted_msgs",
  &_RobotBehaviorCommand_service_typesupport_ids.typesupport_identifier[0],
  &_RobotBehaviorCommand_service_typesupport_symbol_names.symbol_name[0],
  &_RobotBehaviorCommand_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t RobotBehaviorCommand_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RobotBehaviorCommand_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace quadropted_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<quadropted_msgs::srv::RobotBehaviorCommand>()
{
  return &::quadropted_msgs::srv::rosidl_typesupport_cpp::RobotBehaviorCommand_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, quadropted_msgs, srv, RobotBehaviorCommand)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<quadropted_msgs::srv::RobotBehaviorCommand>();
}

#ifdef __cplusplus
}
#endif
