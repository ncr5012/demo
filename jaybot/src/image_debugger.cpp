#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/compressed_image.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <memory>

class ImageDisplayNode : public rclcpp::Node
{
public:
    ImageDisplayNode()
    : Node("image_display_node")
    {
        subscription0_ = this->create_subscription<sensor_msgs::msg::CompressedImage>(
        "camera_image_0", 10, std::bind(&ImageDisplayNode::topic_callback_0, this, std::placeholders::_1));
        
        subscription1_ = this->create_subscription<sensor_msgs::msg::CompressedImage>(
        "camera_image_1", 10, std::bind(&ImageDisplayNode::topic_callback_1, this, std::placeholders::_1));

        // Start the display threads
        display_thread_0_ = std::thread(&ImageDisplayNode::display_image_0, this);
        display_thread_1_ = std::thread(&ImageDisplayNode::display_image_1, this);
    }
    
    ~ImageDisplayNode()
    {
        if(display_thread_0_.joinable())
        {
            display_thread_0_.join();
        }
        if(display_thread_1_.joinable())
        {
            display_thread_1_.join();
        }
    }

private:
    void topic_callback_0(const sensor_msgs::msg::CompressedImage::SharedPtr msg)
    {
        cv::Mat buffer(1, msg->data.size(), CV_8UC1, const_cast<unsigned char*>(msg->data.data()));
        cv::Mat decoded_image = cv::imdecode(buffer, cv::IMREAD_UNCHANGED);
        last_image_data_0_ = decoded_image;
    }
    
    void topic_callback_1(const sensor_msgs::msg::CompressedImage::SharedPtr msg)
    {
        cv::Mat buffer(1, msg->data.size(), CV_8UC1, const_cast<unsigned char*>(msg->data.data()));
        cv::Mat decoded_image = cv::imdecode(buffer, cv::IMREAD_UNCHANGED);
        last_image_data_1_ = decoded_image;
    }

    void display_image_0() {
        while (rclcpp::ok()) {
            if (!last_image_data_0_.empty()) {
                cv::imshow("Image Window 0", last_image_data_0_);
                cv::waitKey(1);
            }
        }
    }
    
    void display_image_1() {
        while (rclcpp::ok()) {
            if (!last_image_data_1_.empty()) {
                cv::imshow("Image Window 1", last_image_data_1_);
                cv::waitKey(1);
            }
        }
    }

    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr subscription0_;
    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr subscription1_;
    cv::Mat last_image_data_0_;
    cv::Mat last_image_data_1_;
    std::thread display_thread_0_;
    std::thread display_thread_1_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto image_display_node = std::make_shared<ImageDisplayNode>();
    rclcpp::spin(image_display_node);
    rclcpp::shutdown();
    return 0;
}




