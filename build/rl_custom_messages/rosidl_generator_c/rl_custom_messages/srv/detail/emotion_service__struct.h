// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rl_custom_messages:srv/EmotionService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__STRUCT_H_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/EmotionService in the package rl_custom_messages.
typedef struct rl_custom_messages__srv__EmotionService_Request
{
  uint8_t structure_needs_at_least_one_member;
} rl_custom_messages__srv__EmotionService_Request;

// Struct for a sequence of rl_custom_messages__srv__EmotionService_Request.
typedef struct rl_custom_messages__srv__EmotionService_Request__Sequence
{
  rl_custom_messages__srv__EmotionService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__srv__EmotionService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'results'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/EmotionService in the package rl_custom_messages.
typedef struct rl_custom_messages__srv__EmotionService_Response
{
  rosidl_runtime_c__String results;
} rl_custom_messages__srv__EmotionService_Response;

// Struct for a sequence of rl_custom_messages__srv__EmotionService_Response.
typedef struct rl_custom_messages__srv__EmotionService_Response__Sequence
{
  rl_custom_messages__srv__EmotionService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__srv__EmotionService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__EMOTION_SERVICE__STRUCT_H_
