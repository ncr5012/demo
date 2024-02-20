#ifndef RANGE_SENSOR
#define RANGE_SENSOR

#include <stdio.h>
#include <iostream>		// Include all needed libraries here
#include <pigpiod_if2.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <deque>
#include <numeric>
#include <vector>


class Rangesensor
{
  public:
    // Constructor. Mainly sets up pins.
    Rangesensor(int trigpin, int echopin);

    ~Rangesensor();      

    // tells if joystick has moved
    double Range();  

	
  private:
    //variables for the 2 inputs
	  int trig, echo;
    double calibration_factor;
    int pi = pigpio_start(NULL,NULL);
    std::deque<std::pair<double, std::chrono::steady_clock::time_point>> measurements;
    std::chrono::duration<double> measurement_duration{0.5}; // Duration to keep measurements (0.5 seconds)


};

//modified code with Rangesensor.cc

Rangesensor::Rangesensor(int trigpin, int echopin)
{
  trig = trigpin;
  echo = echopin;

  if (pi < 0) {
    std::cout << "failed" << "\n";
  }
  
  set_mode(pi, trig, PI_OUTPUT);
  set_mode(pi, echo, PI_INPUT);
  gpio_write(pi, trig, 0);
  //sleep(1);
  std::cout << "initialized" << "\n";

}

Rangesensor::~Rangesensor() 
{
    // Stop the motor
    gpio_write(pi, trig, 0);

    // Disconnect from the pigpiod daemon
    pigpio_stop(pi);
}

double Rangesensor::Range() {
   
  gpio_write(pi, trig, 1);
  std::this_thread::sleep_for(std::chrono::microseconds(2));
  gpio_write(pi, trig, 0);
 
  auto echo_start = std::chrono::steady_clock::now();
  
  while (gpio_read(pi, echo) == 0) {
    auto echo_end = std::chrono::steady_clock::now();
    auto echo_timer = std::chrono::duration_cast<std::chrono::microseconds>(echo_end-echo_start);
    if (echo_timer.count() > 3000) {
      std::cout << "Timeout waiting for echo start" << "\n";
      break;
    }
  }
  
  while (gpio_read(pi, echo) == 1) {
    auto echo_end = std::chrono::steady_clock::now();
    auto echo_timer = std::chrono::duration_cast<std::chrono::microseconds>(echo_end-echo_start);
    if (echo_timer.count() > 50000) {
      std::cout << "Timeout waiting for echo to end" << "\n";
      break;
    }
  }

  auto echo_end = std::chrono::steady_clock::now();
  auto echo_timer = std::chrono::duration_cast<std::chrono::microseconds>(echo_end-echo_start);

  //Consider putting calibration factor as an initialization variable for range sensors if they are different
  double calibration_factor = -43.5;
  double distance = ((echo_timer.count() / 1000000.0) * 17150.0) + calibration_factor;
  
  // Store the measurement with its timestamp
  measurements.emplace_back(distance, echo_end);
  
  // Remove measurements older than measurement_duration
  auto remove_before = echo_end - measurement_duration;

  auto it = measurements.begin();
  while (it != measurements.end()) {
      if (it->second < remove_before) {
          it = measurements.erase(it);
      } else {
          ++it;
      }
  }

  // Calculate the average distance
  double sum = std::accumulate(measurements.begin(), measurements.end(), 0.0,
    [](double acc, const std::pair<double, std::chrono::steady_clock::time_point>& elem) {
      return acc + elem.first;
    });

  double average_distance = sum / measurements.size();

  if (distance < 0) {
    distance = 0;
  }

 // std::cout << "Distance: " << distance << " cm" << "\n";
  //std::cout << "Average Distance (last 0.5s): " << average_distance << " cm" << "\n";
  
 //std::this_thread::sleep_for(std::chrono::milliseconds(20));
  
  return average_distance;
  
}


#endif
