cmake_minimum_required(VERSION 3.5)
project(jaybot)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rl_custom_messages REQUIRED)

# After message generation
add_executable(range_publisher src/range_publisher.cpp)
target_include_directories(range_publisher PUBLIC include)
target_link_libraries(range_publisher ${catkin_LIBRARIES} pigpiod_if2)
ament_target_dependencies(range_publisher rclcpp rl_custom_messages)

add_executable(range_subscriber src/range_subscriber.cpp)
ament_target_dependencies(range_subscriber rclcpp rl_custom_messages)


install(TARGETS
  range_publisher
  range_subscriber
  DESTINATION lib/${PROJECT_NAME})
  
install(
  DIRECTORY include/
  DESTINATION include
  )

ament_export_dependencies(rclcpp rl_custom_messages)
ament_package()


