#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class VelocityPublisherNode : public rclcpp::Node
{
public:
  VelocityPublisherNode() : Node("velocity_publisher_node")
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    timer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
                                     std::bind(&VelocityPublisherNode::publish_velocity, this));
  }

private:
  void publish_velocity()
  {
    auto msg = std::make_unique<geometry_msgs::msg::Twist>();
    msg->linear.x = 0.0;
    msg->linear.z = 0.0;

    msg->angular.z = 0.0;
    msg->angular.x = 0.0;
    publisher_->publish(std::move(msg));
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<VelocityPublisherNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
