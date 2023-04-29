#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class SmartphoneNode : public rclcpp::Node
{
public:
    SmartphoneNode() : Node("smarphone_sub")
    {
        subscriber_ = this->create_subscription<std_msgs::msg::String>("robot_news_topic", 10,
        std::bind(&SmartphoneNode::callbackFunc, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "Publish Node");
    }

private:
void callbackFunc(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
}
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SmartphoneNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}