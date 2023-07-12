// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rl_custom_messages:msg/ImageArray.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/msg/detail/image_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `encoding`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rl_custom_messages__msg__ImageArray__init(rl_custom_messages__msg__ImageArray * msg)
{
  if (!msg) {
    return false;
  }
  // height
  // width
  // encoding
  if (!rosidl_runtime_c__String__init(&msg->encoding)) {
    rl_custom_messages__msg__ImageArray__fini(msg);
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    rl_custom_messages__msg__ImageArray__fini(msg);
    return false;
  }
  return true;
}

void
rl_custom_messages__msg__ImageArray__fini(rl_custom_messages__msg__ImageArray * msg)
{
  if (!msg) {
    return;
  }
  // height
  // width
  // encoding
  rosidl_runtime_c__String__fini(&msg->encoding);
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
rl_custom_messages__msg__ImageArray__are_equal(const rl_custom_messages__msg__ImageArray * lhs, const rl_custom_messages__msg__ImageArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // encoding
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->encoding), &(rhs->encoding)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
rl_custom_messages__msg__ImageArray__copy(
  const rl_custom_messages__msg__ImageArray * input,
  rl_custom_messages__msg__ImageArray * output)
{
  if (!input || !output) {
    return false;
  }
  // height
  output->height = input->height;
  // width
  output->width = input->width;
  // encoding
  if (!rosidl_runtime_c__String__copy(
      &(input->encoding), &(output->encoding)))
  {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

rl_custom_messages__msg__ImageArray *
rl_custom_messages__msg__ImageArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__msg__ImageArray * msg = (rl_custom_messages__msg__ImageArray *)allocator.allocate(sizeof(rl_custom_messages__msg__ImageArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rl_custom_messages__msg__ImageArray));
  bool success = rl_custom_messages__msg__ImageArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rl_custom_messages__msg__ImageArray__destroy(rl_custom_messages__msg__ImageArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rl_custom_messages__msg__ImageArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rl_custom_messages__msg__ImageArray__Sequence__init(rl_custom_messages__msg__ImageArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__msg__ImageArray * data = NULL;

  if (size) {
    data = (rl_custom_messages__msg__ImageArray *)allocator.zero_allocate(size, sizeof(rl_custom_messages__msg__ImageArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rl_custom_messages__msg__ImageArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rl_custom_messages__msg__ImageArray__fini(&data[i - 1]);
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
rl_custom_messages__msg__ImageArray__Sequence__fini(rl_custom_messages__msg__ImageArray__Sequence * array)
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
      rl_custom_messages__msg__ImageArray__fini(&array->data[i]);
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

rl_custom_messages__msg__ImageArray__Sequence *
rl_custom_messages__msg__ImageArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__msg__ImageArray__Sequence * array = (rl_custom_messages__msg__ImageArray__Sequence *)allocator.allocate(sizeof(rl_custom_messages__msg__ImageArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rl_custom_messages__msg__ImageArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rl_custom_messages__msg__ImageArray__Sequence__destroy(rl_custom_messages__msg__ImageArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rl_custom_messages__msg__ImageArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rl_custom_messages__msg__ImageArray__Sequence__are_equal(const rl_custom_messages__msg__ImageArray__Sequence * lhs, const rl_custom_messages__msg__ImageArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rl_custom_messages__msg__ImageArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rl_custom_messages__msg__ImageArray__Sequence__copy(
  const rl_custom_messages__msg__ImageArray__Sequence * input,
  rl_custom_messages__msg__ImageArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rl_custom_messages__msg__ImageArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rl_custom_messages__msg__ImageArray * data =
      (rl_custom_messages__msg__ImageArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rl_custom_messages__msg__ImageArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rl_custom_messages__msg__ImageArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rl_custom_messages__msg__ImageArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
