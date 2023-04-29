#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

class NumberCounterNode : public rclcpp::Node
{
public:
    NumberCounterNode() : Node("number_counter")
    {
        num_sub = this->create_subscription<std_msgs::msg::Int64>("number", 10,
                                            std::bind(&NumberCounterNode::callbackFunc, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "Subscriber & Publisher Node");

        counter_pub = this->create_publisher<std_msgs::msg::Int64>("number_counter", 10);
    }

private:
void callbackFunc(const std_msgs::msg::Int64::SharedPtr msg)
{
   // RCLCPP_INFO(this->get_logger(), "%ld", msg->data);


                auto count = std_msgs::msg::Int64();
                count.data = i++;
                counter_pub -> publish(count);
                
        //RCLCPP_INFO(this->get_logger(), "%d", sum);
  
}
    int i = 0;
    int sum = 0;

    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr num_sub;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr counter_pub;

};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}

