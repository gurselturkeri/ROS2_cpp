cmake_minimum_required(VERSION 3.5)
project(pid_controller)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(include)

add_executable(pid_controller_node src/main.cpp src/pid.cpp)
ament_target_dependencies(pid_controller_node rclcpp)

install(TARGETS
  pid_controller_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
