#include "rclcpp/rclcpp.hpp"

class MyNode: public rclcpp::Node

{
public:
    MyNode(): Node("cpp_test"), counter_(0)
    {
        RCLCPP_INFO(this->get_logger(),"Hello Cpp Node");
        timer_ = this->create_wall_timer(std::chrono::seconds(1),               // her 1 saniyede data gonderiyor
                                        std::bind(&MyNode::timerCallback, this) // timer ile fonksiyonu bağladık
        );
    }

private:

void timerCallback()  // call function in a given rate
{
    counter_++;
    RCLCPP_INFO(this->get_logger(),"Gursel %d", counter_); // %d bir tamsayı değişkeni içeren bir yer tutucusu olarak işlev görür.
}

rclcpp::TimerBase::SharedPtr timer_;
int counter_;

};

int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv); // initilaze ROS communication
    auto node = std::make_shared<MyNode>(); // dinamik bellekte bir nesne oluşturur ve onunla ilişkili bir std::shared_ptr nesnesi döndürür.
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
