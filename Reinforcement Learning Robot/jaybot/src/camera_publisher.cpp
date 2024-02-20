#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/compressed_image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <rclcpp/executors/multi_threaded_executor.hpp>
#include "rl_custom_messages/srv/image_service.hpp"

sensor_msgs::msg::CompressedImage::SharedPtr toCompressedImageMsg(cv::Mat frame) {
    // Compress frame to jpeg
    std::vector<uint8_t> buffer;
    cv::imencode(".jpg", frame, buffer);

    auto image_msg = std::make_shared<sensor_msgs::msg::CompressedImage>();
    image_msg->data = buffer;
    image_msg->format = "jpeg";

    return image_msg;
}

class ImageServiceServer : public rclcpp::Node
{
public:
    ImageServiceServer(int id, std::string service_name)
    : Node("image_service_server_" + std::to_string(id)), cap{id + cv::CAP_V4L}
    {
        service_ = this->create_service<rl_custom_messages::srv::ImageService>(
            service_name, std::bind(&ImageServiceServer::service_callback, this, std::placeholders::_1, std::placeholders::_2));

        cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
        cap.set(cv::CAP_PROP_FPS, 30);

        if(!cap.isOpened()) {
            RCLCPP_ERROR(this->get_logger(), "Cannot open camera");
        }
    }

private:
    void service_callback(const std::shared_ptr<rl_custom_messages::srv::ImageService::Request> request,
                          std::shared_ptr<rl_custom_messages::srv::ImageService::Response> response)
    {
        cv::Mat frame;
        cap >> frame;
        if (!frame.empty()) {
            response->image_data = *toCompressedImageMsg(frame);
        }
    }

    rclcpp::Service<rl_custom_messages::srv::ImageService>::SharedPtr service_;
    cv::VideoCapture cap;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor executor;

    auto image_service_server_0 = std::make_shared<ImageServiceServer>(0, "/get_image_data_camera_image_0");
    auto image_service_server_1 = std::make_shared<ImageServiceServer>(2, "/get_image_data_camera_image_1");

    executor.add_node(image_service_server_0);
    executor.add_node(image_service_server_1);

    executor.spin();

    rclcpp::shutdown();
    return 0;
}
