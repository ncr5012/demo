// image_debugger.cpp

#include <rclcpp/rclcpp.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/msg/image.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <memory>

class ImageDisplayNode : public rclcpp::Node
{
public:
    ImageDisplayNode()
    : Node("image_display_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "camera_image", 10, std::bind(&ImageDisplayNode::topic_callback, this, std::placeholders::_1));

        // Start the display thread
        display_thread_ = std::thread(&ImageDisplayNode::display_image, this);
    }

private:
    void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        }
        catch (cv_bridge::Exception& e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }
        last_image_data_ = cv_ptr->image;
    }

    void display_image() {
        while (rclcpp::ok()) {
            if (!last_image_data_.empty()) {
                cv::imshow("Image Window", last_image_data_);
                cv::waitKey(1);
            }
        }
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    cv::Mat last_image_data_;
    std::thread display_thread_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto image_display_node = std::make_shared<ImageDisplayNode>();
    rclcpp::spin(image_display_node);
    rclcpp::shutdown();
    return 0;
}




