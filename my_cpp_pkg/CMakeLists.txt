cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp  REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_typesupport_cpp REQUIRED)
find_package(example_interfaces REQUIRED)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(cpp_node src/my_first_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(cpp_node_oop src/my_first_node_oop.cpp)
ament_target_dependencies(cpp_node_oop rclcpp)

add_executable(control_cpp src/control.cpp)
ament_target_dependencies(control_cpp rclcpp geometry_msgs rosidl_typesupport_cpp)

add_executable(robot_news_station src/robot_news_station.cpp)
ament_target_dependencies(robot_news_station rclcpp std_msgs)

add_executable(smartphone src/smartphone.cpp)
ament_target_dependencies(smartphone rclcpp std_msgs)

add_executable(number_publisher src/number_publisher.cpp)
ament_target_dependencies(number_publisher rclcpp std_msgs)

add_executable(number_counter src/number_counter.cpp)
ament_target_dependencies(number_counter rclcpp std_msgs)

ament_export_dependencies(rclcpp geometry_msgs rosidl_typesupport_cpp)
install(TARGETS
  cpp_node
  cpp_node_oop
  control_cpp
  robot_news_station
  smartphone
  number_publisher
  number_counter
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
