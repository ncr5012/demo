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
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(rl_custom_messages REQUIRED)

include_directories(include)

# After message generation
add_executable(range_publisher src/range_publisher.cpp)
target_include_directories(range_publisher PUBLIC include)
target_link_libraries(range_publisher ${catkin_LIBRARIES} pigpiod_if2)
ament_target_dependencies(range_publisher rclcpp rl_custom_messages)

add_executable(rl_server src/rl_server.cpp)
ament_target_dependencies(rl_server rclcpp rl_custom_messages)


install(TARGETS
  range_publisher
  rl_server
  DESTINATION lib/${PROJECT_NAME})
  
install(
  DIRECTORY include/
  DESTINATION include
  )
  
ament_python_install_package(${PROJECT_NAME})

install(PROGRAMS
  scripts/rl_mind.py
  DESTINATION lib/${PROJECT_NAME}
)
ament_export_dependencies(rclcpp rl_custom_messages)
ament_package()



