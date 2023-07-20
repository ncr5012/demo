// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rl_custom_messages:srv/ImageService.idl
// generated code does not contain a copyright notice

#ifndef RL_CUSTOM_MESSAGES__SRV__DETAIL__IMAGE_SERVICE__STRUCT_H_
#define RL_CUSTOM_MESSAGES__SRV__DETAIL__IMAGE_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ImageService in the package rl_custom_messages.
typedef struct rl_custom_messages__srv__ImageService_Request
{
  uint8_t structure_needs_at_least_one_member;
} rl_custom_messages__srv__ImageService_Request;

// Struct for a sequence of rl_custom_messages__srv__ImageService_Request.
typedef struct rl_custom_messages__srv__ImageService_Request__Sequence
{
  rl_custom_messages__srv__ImageService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__srv__ImageService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'image_data'
#include "sensor_msgs/msg/detail/compressed_image__struct.h"

/// Struct defined in srv/ImageService in the package rl_custom_messages.
typedef struct rl_custom_messages__srv__ImageService_Response
{
  sensor_msgs__msg__CompressedImage image_data;
} rl_custom_messages__srv__ImageService_Response;

// Struct for a sequence of rl_custom_messages__srv__ImageService_Response.
typedef struct rl_custom_messages__srv__ImageService_Response__Sequence
{
  rl_custom_messages__srv__ImageService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rl_custom_messages__srv__ImageService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RL_CUSTOM_MESSAGES__SRV__DETAIL__IMAGE_SERVICE__STRUCT_H_
