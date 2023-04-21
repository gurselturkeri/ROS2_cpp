#include "rclcpp/rclcpp.hpp"

int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv); // initilaze ROS communication
    auto node = std::make_shared<rclcpp::Node>("cpp_test"); // create shared pointer to node
    RCLCPP_INFO(node->get_logger(),"Hello Cpp Node");
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
