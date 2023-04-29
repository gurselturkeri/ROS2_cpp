#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include <iostream>

class NumberPublisherNode : public rclcpp::Node
{
public:
    NumberPublisherNode() : Node("number_publisher")

    {
        num_pub = this->create_publisher<std_msgs::msg::Int64>("number", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
                                         std::bind(&NumberPublisherNode::publishNumber, this));
        RCLCPP_INFO(this->get_logger(),"Number Publisher Node has been started");
    }


private:
    void publishNumber(){
        auto msg = std_msgs::msg::Int64();
           // do not need for loop 
           // code already loop every 1 second due to timer
            msg.data = i;
            std::cout << "i: " << i << " " << "msg: " << msg.data << std::endl;
            num_pub -> publish(msg);
            i = i+ 2;
            
        
        
    }
     int i;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr num_pub;
    rclcpp::TimerBase::SharedPtr timer_;

};


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}