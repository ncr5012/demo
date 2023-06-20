#ifndef MOTOR_CONTROLLER
#define MOTOR_CONTROLLER

#include <stdio.h>
#include <iostream>		// Include all needed libraries here
#include <pigpiod_if2.h>
#include <unistd.h>
#include <rclcpp/rclcpp.hpp>
#include "rl_custom_messages/msg/motor_commands.hpp"


class Motor
{
  public:
    // Constructor. Mainly sets up pins.
    Motor(int In1pin, int In2pin, int PWMpin, int offset);   

	~Motor();   

    // Drive in direction given by sign, at speed given by magnitude of the 
	//parameter.
    void commands(int dir1, int dir2, int speed);  

	
  private:
    //variables for the 2 inputs, PWM input, Offset value, and the Standby pin
	int In1, In2, PWM, Offset;
	int pi = pigpio_start(NULL,NULL);
	
	//private functions that spin the motor CC and CCW


};


Motor::Motor(int In1pin, int In2pin, int PWMpin, int offset)
{
  In1 = In1pin;
  In2 = In2pin;
  PWM = PWMpin;
  Offset = offset;
  
  if (pi < 0) {
    std::cout << "failed" << "\n";
  }
  
  set_mode(pi, In1, PI_OUTPUT);
  set_mode(pi, In2, PI_OUTPUT);
  set_PWM_frequency(pi, PWM, 10);
  set_PWM_range(pi, PWM, 100);
  std::cout << "initialized" << "\n";

}

Motor::~Motor() 
{
    // Stop the motor
    gpio_write(pi, In1, 0);
    gpio_write(pi, In2, 0);
    set_PWM_dutycycle(pi, PWM, 0);

    // Disconnect from the pigpiod daemon
    pigpio_stop(pi);
}


void Motor::commands(int dir1, int dir2, int speed)
{
   gpio_write(pi, In1, dir1);
   gpio_write(pi, In2, dir2);
   set_PWM_dutycycle(pi, PWM, speed);

}








#endif
