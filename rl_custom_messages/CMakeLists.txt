cmake_minimum_required(VERSION 3.8)
project(rl_custom_messages)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(sensor_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/RangeArray.msg"
  "msg/MotorCommands.msg"
  "msg/AudioData.msg"
  "srv/ObservationService.srv"
  "srv/ImageService.srv"
  "srv/EmotionService.srv"
  DEPENDENCIES sensor_msgs
)


ament_package()
