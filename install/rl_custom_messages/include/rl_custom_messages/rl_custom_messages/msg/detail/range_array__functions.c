// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rl_custom_messages:msg/RangeArray.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/msg/detail/range_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rl_custom_messages__msg__RangeArray__init(rl_custom_messages__msg__RangeArray * msg)
{
  if (!msg) {
    return false;
  }
  // range_left
  // range_front
  // range_right
  // range_back
  return true;
}

void
rl_custom_messages__msg__RangeArray__fini(rl_custom_messages__msg__RangeArray * msg)
{
  if (!msg) {
    return;
  }
  // range_left
  // range_front
  // range_right
  // range_back
}

bool
rl_custom_messages__msg__RangeArray__are_equal(const rl_custom_messages__msg__RangeArray * lhs, const rl_custom_messages__msg__RangeArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // range_left
  if (lhs->range_left != rhs->range_left) {
    return false;
  }
  // range_front
  if (lhs->range_front != rhs->range_front) {
    return false;
  }
  // range_right
  if (lhs->range_right != rhs->range_right) {
    return false;
  }
  // range_back
  if (lhs->range_back != rhs->range_back) {
    return false;
  }
  return true;
}

bool
rl_custom_messages__msg__RangeArray__copy(
  const rl_custom_messages__msg__RangeArray * input,
  rl_custom_messages__msg__RangeArray * output)
{
  if (!input || !output) {
    return false;
  }
  // range_left
  output->range_left = input->range_left;
  // range_front
  output->range_front = input->range_front;
  // range_right
  output->range_right = input->range_right;
  // range_back
  output->range_back = input->range_back;
  return true;
}

rl_custom_messages__msg__RangeArray *
rl_custom_messages__msg__RangeArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__msg__RangeArray * msg = (rl_custom_messages__msg__RangeArray *)allocator.allocate(sizeof(rl_custom_messages__msg__RangeArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rl_custom_messages__msg__RangeArray));
  bool success = rl_custom_messages__msg__RangeArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rl_custom_messages__msg__RangeArray__destroy(rl_custom_messages__msg__RangeArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rl_custom_messages__msg__RangeArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rl_custom_messages__msg__RangeArray__Sequence__init(rl_custom_messages__msg__RangeArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__msg__RangeArray * data = NULL;

  if (size) {
    data = (rl_custom_messages__msg__RangeArray *)allocator.zero_allocate(size, sizeof(rl_custom_messages__msg__RangeArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rl_custom_messages__msg__RangeArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rl_custom_messages__msg__RangeArray__fini(&data[i - 1]);
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
rl_custom_messages__msg__RangeArray__Sequence__fini(rl_custom_messages__msg__RangeArray__Sequence * array)
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
      rl_custom_messages__msg__RangeArray__fini(&array->data[i]);
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

rl_custom_messages__msg__RangeArray__Sequence *
rl_custom_messages__msg__RangeArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rl_custom_messages__msg__RangeArray__Sequence * array = (rl_custom_messages__msg__RangeArray__Sequence *)allocator.allocate(sizeof(rl_custom_messages__msg__RangeArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rl_custom_messages__msg__RangeArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rl_custom_messages__msg__RangeArray__Sequence__destroy(rl_custom_messages__msg__RangeArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rl_custom_messages__msg__RangeArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rl_custom_messages__msg__RangeArray__Sequence__are_equal(const rl_custom_messages__msg__RangeArray__Sequence * lhs, const rl_custom_messages__msg__RangeArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rl_custom_messages__msg__RangeArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rl_custom_messages__msg__RangeArray__Sequence__copy(
  const rl_custom_messages__msg__RangeArray__Sequence * input,
  rl_custom_messages__msg__RangeArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rl_custom_messages__msg__RangeArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rl_custom_messages__msg__RangeArray * data =
      (rl_custom_messages__msg__RangeArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rl_custom_messages__msg__RangeArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rl_custom_messages__msg__RangeArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rl_custom_messages__msg__RangeArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}