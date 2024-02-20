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
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS} ${sensor_msgs_INCLUDE_DIRS} ${cv_bridge_INCLUDE_DIRS})

# After message generation
add_executable(range_publisher src/range_publisher.cpp)
target_include_directories(range_publisher PUBLIC include)
target_link_libraries(range_publisher ${catkin_LIBRARIES} pigpiod_if2)
ament_target_dependencies(range_publisher rclcpp rl_custom_messages)

add_executable(motor_controller src/motor_controller.cpp)
target_include_directories(motor_controller PUBLIC include)
target_link_libraries(motor_controller ${catkin_LIBRARIES} pigpiod_if2)
ament_target_dependencies(motor_controller rclcpp rl_custom_messages)

add_executable(camera_publisher src/camera_publisher.cpp)
target_link_libraries(camera_publisher ${OpenCV_LIBS} ${cv_bridge_LIBS})
ament_target_dependencies(camera_publisher rclcpp rl_custom_messages cv_bridge)

add_executable(microphone_publisher src/microphone_publisher.cpp)
target_link_libraries(microphone_publisher ${sensor_msgs_LIBS} asound)
ament_target_dependencies(microphone_publisher rclcpp rl_custom_messages)

add_executable(speaker_controller src/speaker_controller.cpp)
target_link_libraries(speaker_controller ${sensor_msgs_LIBS} asound)
ament_target_dependencies(speaker_controller rclcpp rl_custom_messages)

add_executable(rl_server src/rl_server.cpp)
target_link_libraries(rl_server ${OpenCV_LIBS} ${cv_bridge_LIBS})
ament_target_dependencies(rl_server rclcpp rl_custom_messages cv_bridge)

add_executable(image_debugger src/image_debugger.cpp)
target_link_libraries(image_debugger ${OpenCV_LIBS} ${cv_bridge_LIBS})
ament_target_dependencies(image_debugger rclcpp rl_custom_messages cv_bridge)


install(TARGETS
  range_publisher
  motor_controller
  camera_publisher
  microphone_publisher
  speaker_controller
  rl_server
  image_debugger
  DESTINATION lib/${PROJECT_NAME})
  
install(
  DIRECTORY include/
  DESTINATION include
  )
  
ament_python_install_package(${PROJECT_NAME})

install(PROGRAMS
  scripts/rl_mind.py
  scripts/face_detection_test.py
  scripts/emotion_server.py
  DESTINATION lib/${PROJECT_NAME}
)
ament_export_dependencies(rclcpp rl_custom_messages sensor_msgs)
ament_package()



