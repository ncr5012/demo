// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rl_custom_messages:srv/ObservationService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__STRUCT_H_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ObservationService in the package rl_custom_messages.
typedef struct rl_custom_messages__srv__ObservationService_Request
{
  uint8_t structure_needs_at_least_one_member;
} rl_custom_messages__srv__ObservationService_Request;

// Struct for a sequence of rl_custom_messages__srv__ObservationService_Request.
typedef struct rl_custom_messages__srv__ObservationService_Request__Sequence
{
  rl_custom_messages__srv__ObservationService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__srv__ObservationService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'range_data'
#include "rl_custom_messages/msg/detail/range_array__struct.h"

/// Struct defined in srv/ObservationService in the package rl_custom_messages.
typedef struct rl_custom_messages__srv__ObservationService_Response
{
  rl_custom_messages__msg__RangeArray range_data;
} rl_custom_messages__srv__ObservationService_Response;

// Struct for a sequence of rl_custom_messages__srv__ObservationService_Response.
typedef struct rl_custom_messages__srv__ObservationService_Response__Sequence
{
  rl_custom_messages__srv__ObservationService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__srv__ObservationService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__OBSERVATION_SERVICE__STRUCT_H_
