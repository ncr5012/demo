#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>

sensor_msgs::msg::Image::SharedPtr toImageMsg(cv::Mat frame) {
    cv_bridge::CvImage cv_image;
    cv_image.image = frame;
    cv_image.encoding = "bgr8";
    return cv_image.toImageMsg();
}

class ImagePublisher : public rclcpp::Node
{
public:
    ImagePublisher()
    : Node("image_publisher")
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("camera_image", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(200), std::bind(&ImagePublisher::timer_callback, this));
        cap.set(cv::CAP_PROP_FRAME_WIDTH, 640); // change the resolution here
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480); // change the resolution here
        cap.set(cv::CAP_PROP_FPS, 5);
        if(!cap.isOpened()) {
            RCLCPP_ERROR(this->get_logger(), "Cannot open camera");
        }
    }

private:
    void timer_callback() {
        cv::Mat frame;
        cap >> frame;
        if(!frame.empty()) {
            publish(frame);
        }
    }

    void publish(cv::Mat frame) {
        auto message = toImageMsg(frame);
        publisher_->publish(*message);
    }

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    cv::VideoCapture cap{1 + cv::CAP_V4L};
};


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ImagePublisher>());
    rclcpp::shutdown();
    return 0;
}


