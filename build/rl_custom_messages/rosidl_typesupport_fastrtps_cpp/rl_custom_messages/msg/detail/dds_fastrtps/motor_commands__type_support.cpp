// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rl_custom_messages:msg/MotorCommands.idl
// generated code does not contain a copyright notice
#include "rl_custom_messages/msg/detail/motor_commands__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rl_custom_messages/msg/detail/motor_commands__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rl_custom_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
cdr_serialize(
  const rl_custom_messages::msg::MotorCommands & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: commands
  {
    cdr << ros_message.commands;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rl_custom_messages::msg::MotorCommands & ros_message)
{
  // Member: commands
  {
    cdr >> ros_message.commands;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
get_serialized_size(
  const rl_custom_messages::msg::MotorCommands & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: commands
  {
    size_t array_size = ros_message.commands.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.commands[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rl_custom_messages
max_serialized_size_MotorCommands(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: commands
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _MotorCommands__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rl_custom_messages::msg::MotorCommands *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MotorCommands__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rl_custom_messages::msg::MotorCommands *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MotorCommands__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rl_custom_messages::msg::MotorCommands *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MotorCommands__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MotorCommands(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MotorCommands__callbacks = {
  "rl_custom_messages::msg",
  "MotorCommands",
  _MotorCommands__cdr_serialize,
  _MotorCommands__cdr_deserialize,
  _MotorCommands__get_serialized_size,
  _MotorCommands__max_serialized_size
};

static rosidl_message_type_support_t _MotorCommands__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MotorCommands__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rl_custom_messages

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rl_custom_messages
const rosidl_message_type_support_t *
get_message_type_support_handle<rl_custom_messages::msg::MotorCommands>()
{
  return &rl_custom_messages::msg::typesupport_fastrtps_cpp::_MotorCommands__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rl_custom_messages, msg, MotorCommands)() {
  return &rl_custom_messages::msg::typesupport_fastrtps_cpp::_MotorCommands__handle;
}

#ifdef __cplusplus
}
#endif