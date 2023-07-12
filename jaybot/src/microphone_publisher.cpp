#include <alsa/asoundlib.h>
#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include "rl_custom_messages/msg/audio_data.hpp"

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define CHANNELS 1

class AudioCapturePublisher : public rclcpp::Node
{
public:
    AudioCapturePublisher()
    : Node("audio_capture_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<rl_custom_messages::msg::AudioData>("audio_data", 10);
        timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&AudioCapturePublisher::timer_callback, this));
        snd_pcm_open(&capture_handle_, "hw:1", SND_PCM_STREAM_CAPTURE, 0);
        snd_pcm_set_params(capture_handle_,
                           SND_PCM_FORMAT_S16_LE,
                           SND_PCM_ACCESS_RW_INTERLEAVED,
                           CHANNELS,
                           SAMPLE_RATE,
                           1,
                           500000);  // 0.5 sec
    }

private:
    void timer_callback()
    {
        auto message = rl_custom_messages::msg::AudioData();
        snd_pcm_uframes_t frames = FRAME_SIZE;
        char *buffer = (char *) malloc(frames * 2 * CHANNELS); // 16 bits mono

        snd_pcm_readi(capture_handle_, buffer, frames);

        // Convert char buffer to uint16_t vector
        std::vector<int16_t> data_vec;
        for(size_t i = 0; i < frames * 2 * CHANNELS; i += 2) {
            int16_t val = *(int16_t *) &buffer[i];
            data_vec.push_back(val);
        }

        message.data = data_vec;
        publisher_->publish(message);

        free(buffer);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<rl_custom_messages::msg::AudioData>::SharedPtr publisher_;
    snd_pcm_t *capture_handle_;
    size_t count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AudioCapturePublisher>());
    rclcpp::shutdown();
    return 0;
}
