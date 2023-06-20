// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rl_custom_messages:srv/ObservationService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rl_custom_messages/srv/detail/observation_service__rosidl_typesupport_introspection_c.h"
#include "rl_custom_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rl_custom_messages/srv/detail/observation_service__functions.h"
#include "rl_custom_messages/srv/detail/observation_service__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rl_custom_messages__srv__ObservationService_Request__init(message_memory);
}

void rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_fini_function(void * message_memory)
{
  rl_custom_messages__srv__ObservationService_Request__fini(message_memory);
}

size_t rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__size_function__ObservationService_Request__action(
  const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__get_const_function__ObservationService_Request__action(
  const void * untyped_member, size_t index)
{
  const int32_t * member =
    (const int32_t *)(untyped_member);
  return &member[index];
}

void * rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__get_function__ObservationService_Request__action(
  void * untyped_member, size_t index)
{
  int32_t * member =
    (int32_t *)(untyped_member);
  return &member[index];
}

void rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__fetch_function__ObservationService_Request__action(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__get_const_function__ObservationService_Request__action(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__assign_function__ObservationService_Request__action(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__get_function__ObservationService_Request__action(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_message_member_array[1] = {
  {
    "action",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__srv__ObservationService_Request, action),  // bytes offset in struct
    NULL,  // default value
    rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__size_function__ObservationService_Request__action,  // size() function pointer
    rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__get_const_function__ObservationService_Request__action,  // get_const(index) function pointer
    rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__get_function__ObservationService_Request__action,  // get(index) function pointer
    rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__fetch_function__ObservationService_Request__action,  // fetch(index, &value) function pointer
    rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__assign_function__ObservationService_Request__action,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_message_members = {
  "rl_custom_messages__srv",  // message namespace
  "ObservationService_Request",  // message name
  1,  // number of fields
  sizeof(rl_custom_messages__srv__ObservationService_Request),
  rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_message_member_array,  // message members
  rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_message_type_support_handle = {
  0,
  &rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rl_custom_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, srv, ObservationService_Request)() {
  if (!rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_message_type_support_handle.typesupport_identifier) {
    rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rl_custom_messages__srv__ObservationService_Request__rosidl_typesupport_introspection_c__ObservationService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rl_custom_messages/srv/detail/observation_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rl_custom_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rl_custom_messages/srv/detail/observation_service__functions.h"
// already included above
// #include "rl_custom_messages/srv/detail/observation_service__struct.h"


// Include directives for member types
// Member `range_data`
#include "rl_custom_messages/msg/range_array.h"
// Member `range_data`
#include "rl_custom_messages/msg/detail/range_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rl_custom_messages__srv__ObservationService_Response__init(message_memory);
}

void rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_fini_function(void * message_memory)
{
  rl_custom_messages__srv__ObservationService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_member_array[1] = {
  {
    "range_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rl_custom_messages__srv__ObservationService_Response, range_data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_members = {
  "rl_custom_messages__srv",  // message namespace
  "ObservationService_Response",  // message name
  1,  // number of fields
  sizeof(rl_custom_messages__srv__ObservationService_Response),
  rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_member_array,  // message members
  rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_type_support_handle = {
  0,
  &rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rl_custom_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, srv, ObservationService_Response)() {
  rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, msg, RangeArray)();
  if (!rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_type_support_handle.typesupport_identifier) {
    rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rl_custom_messages__srv__ObservationService_Response__rosidl_typesupport_introspection_c__ObservationService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rl_custom_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rl_custom_messages/srv/detail/observation_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_service_members = {
  "rl_custom_messages__srv",  // service namespace
  "ObservationService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_Request_message_type_support_handle,
  NULL  // response message
  // rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_Response_message_type_support_handle
};

static rosidl_service_type_support_t rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_service_type_support_handle = {
  0,
  &rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, srv, ObservationService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, srv, ObservationService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rl_custom_messages
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, srv, ObservationService)() {
  if (!rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_service_type_support_handle.typesupport_identifier) {
    rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, srv, ObservationService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rl_custom_messages, srv, ObservationService_Response)()->data;
  }

  return &rl_custom_messages__srv__detail__observation_service__rosidl_typesupport_introspection_c__ObservationService_service_type_support_handle;
}
