#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
using namespace std;
using namespace cv;


CascadeClassifier face_cascade;
class FaceDetectOpencv : public rclcpp::Node 
{
public:
    FaceDetectOpencv() : Node("face_detect")
    {
        classPub = this->create_publisher<std_msgs::msg::String>("isDetect",10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                         std::bind(&FaceDetectOpencv::facePublisher, this));
        RCLCPP_INFO(this->get_logger(), "Node started");

    }

    int detectConfig(){
        String face_cascade_name = "/home/gursel/Desktop/Modern C++ for Computer Vision/Youtube/calisma/haarcascade_frontalface_alt.xml";
        
        if( !face_cascade.load( face_cascade_name ) )
    {
        cout << "--(!)Error loading face cascade\n";
        return -1;
    };
    cout << "Loaded !" << endl;

    //-- 1. Load the cascades
   
    VideoCapture capture(0);
    //-- 2. Read the video stream
 
    if ( ! capture.isOpened() )
    {
        cout << "--(!)Error opening video capture\n";
        return -1;
    }
    Mat frame;
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            cout << "--(!) No captured frame -- Break!\n";
            break;
        }
        //-- 3. Apply the classifier to the frame
        detectFace(frame);
        if( waitKey(10) == 27 )
        {
            break; // escape
        }
    }

    return 0;
    }



private:

    void detectFace(Mat frame){
        Mat frame_gray;
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        std::vector<Rect> faces;
        face_cascade.detectMultiScale(frame_gray, faces);   

        for (size_t i = 0; i<faces.size(); i++)
        {
            Point center(faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2);
            ellipse(frame, center, Size(faces[i].width/2, faces[i].height/2),
            0, 0, 360, Scalar(255,0,255),4);
            Mat faceROI = frame_gray(faces[i]);
        }
        imshow( "Capture - Face detection", frame );
        
        
    }

    void facePublisher(){

        

    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr classPub;
    rclcpp::TimerBase::SharedPtr timer_;

    

};

int main(int argc, char **argv){
    rclcpp::init(argc,argv);
    auto node = std::make_shared<FaceDetectOpencv>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    //detectConfig();
    

}