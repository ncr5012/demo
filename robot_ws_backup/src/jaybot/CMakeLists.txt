cmake_minimum_required(VERSION 3.8)
project(jaybot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rl_custom_messages REQUIRED)

add_executable(range_publisher src/range_publisher.cpp)
target_include_directories(range_publisher PUBLIC include)
target_link_libraries(range_publisher ${catkin_LIBRARIES} pigpiod_if2)
ament_target_dependencies(range_publisher rclcpp rl_custom_messages)

add_executable(motor_controller src/motor_controller.cpp)
target_include_directories(motor_controller PUBLIC include)
target_link_libraries(motor_controller ${catkin_LIBRARIES} pigpiod_if2)
ament_target_dependencies(motor_controller rclcpp rl_custom_messages)

install(TARGETS
  range_publisher
  motor_controller
  DESTINATION lib/${PROJECT_NAME})

install(
  DIRECTORY include/
  DESTINATION include
)

ament_export_dependencies(rclcpp rl_custom_messages)
ament_package()
