#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/compressed_image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <rclcpp/executors/multi_threaded_executor.hpp>

sensor_msgs::msg::CompressedImage::SharedPtr toCompressedImageMsg(cv::Mat frame) {
    // Compress frame to jpeg
    std::vector<uint8_t> buffer;
    cv::imencode(".jpg", frame, buffer);

    auto image_msg = std::make_shared<sensor_msgs::msg::CompressedImage>();
    image_msg->data = buffer;
    image_msg->format = "jpeg";

    return image_msg;
}

class ImagePublisher : public rclcpp::Node
{
public:
    ImagePublisher(int id, std::string topic)
    : Node("image_publisher_" + std::to_string(id)), cap{id + cv::CAP_V4L}
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::CompressedImage>(topic, 10);
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
        auto message = toCompressedImageMsg(frame);
        publisher_->publish(*message);
    }

    rclcpp::Publisher<sensor_msgs::msg::CompressedImage>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    cv::VideoCapture cap;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor executor;

    auto image_publisher_0 = std::make_shared<ImagePublisher>(0, "camera_image_0");
    auto image_publisher_1 = std::make_shared<ImagePublisher>(1, "camera_image_1");

    executor.add_node(image_publisher_0);
    executor.add_node(image_publisher_1);

    executor.spin();

    rclcpp::shutdown();
    return 0;
}

