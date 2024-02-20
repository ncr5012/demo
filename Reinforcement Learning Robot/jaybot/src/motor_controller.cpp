#include "jaybot/motor_controller.h"

//Front pins 


//Front left pins
int PWMFL = 21;
int FLIN1 = 20;
int FLIN2 = 16;


//Front right pins

int PWMFR = 12;
int FRIN1 = 7;
int FRIN2 = 8;



//Back left pins
int PWMRL = 26;
int RLIN1 = 19;
int RLIN2 = 13;

//Back right pins


int PWMRR = 6;
int RRIN1 = 5;
int RRIN2 = 11;

// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetFL = -1;
const int offsetFR = 1;
const int offsetRL = -1;
const int offsetRR = 1;

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("motor_controller_node");

    // Initialize motors as before
    Motor motorFL = Motor(FLIN1, FLIN2, PWMFL, offsetFL);
    Motor motorFR = Motor(FRIN1, FRIN2, PWMFR, offsetFR);
    Motor motorRL = Motor(RLIN1, RLIN2, PWMRL, offsetRL);
    Motor motorRR = Motor(RRIN1, RRIN2, PWMRR, offsetRR);

    /*
    motorFL.commands(1,0,50);
    motorFR.commands(0,1,50);
    motorRL.commands(0,1,50);
    motorRR.commands(1,0,50);
    */

    // Array to hold the motors for easier access
    std::array<Motor, 4> motors = {motorFL, motorFR, motorRL, motorRR};

    // Subscriber
    auto subscription = node->create_subscription<rl_custom_messages::msg::MotorCommands>(
        "motor_commands", 10,
        [node, &motors](rl_custom_messages::msg::MotorCommands::UniquePtr msg) {
            // Ensure there are enough values for all the motors
            if (msg->commands.size() != motors.size() * 3) {
                RCLCPP_ERROR(node->get_logger(), "Received incorrect number of motor commands.");
                return;
            }
    
            // Execute commands for each motor
            for (std::size_t i = 0; i < motors.size(); i++) {
                int idx = i * 3; // Index for command retrieval
                motors[i].commands(msg->commands[idx], msg->commands[idx + 1], msg->commands[idx + 2]);
                RCLCPP_INFO(node->get_logger(), "Motor %zu commands - dir1: %d, dir2: %d, speed: %d",
                i, msg->commands[idx], msg->commands[idx + 1], msg->commands[idx + 2]);

            }
        }
    );

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
