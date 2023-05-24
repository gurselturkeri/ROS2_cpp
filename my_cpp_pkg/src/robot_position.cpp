#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include <iostream>
#include <array> 
#include <unistd.h>

class RobotPositionNode : public rclcpp::Node
{
public:
    RobotPositionNode() : Node("robotPositionData")
    {
        pos_data = this->create_publisher<std_msgs::msg::Float64>("pos_data", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&RobotPositionNode::publishPosition, this));

        

    }

private:

    
    void publishPosition(){

        float posFromSensor[] = {1.7, 5.47, 3.04, 7.42, 4.93, 5.41,
                                 4.22, 5.74, 10.0, 4.67, 7.13};
        int lenghtOfArray = std::end(posFromSensor)-std::begin(posFromSensor);  
        auto msg = std_msgs::msg::Float64();

        for ( int i=0;i<lenghtOfArray;i++){

            msg.data = posFromSensor[i];
            pos_data -> publish(msg);
            usleep(1000000);  // listenin içindeki elemanların tek tek gitmesi için

        }
        
        std::cout <<   " " << std::endl;

    }

rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pos_data;
rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotPositionNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;


}