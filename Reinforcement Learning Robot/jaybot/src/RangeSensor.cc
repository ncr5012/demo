#include "jaybot/RangeSensor.h"

Rangesensor::Rangesensor(int trigpin, int echopin)
{
  trig = trigpin;
  echo = echopin;
  
  if (gpioInitialise() < 0) {
    std::cout << "failed" << "\n";
  }
  
  gpioSetMode(trig, PI_OUTPUT);
  gpioSetMode(echo, PI_INPUT);
  gpioWrite(trig, 0);
  //sleep(1);
  std::cout << "initialized" << "\n";

}

double Rangesensor::Range() {
   
  gpioWrite(trig, 1);
  std::this_thread::sleep_for(std::chrono::microseconds(2));
  gpioWrite(trig, 0);
 
  auto echo_start = std::chrono::steady_clock::now();
  
  while (gpioRead(echo) == 0) {
    auto echo_end = std::chrono::steady_clock::now();
    auto echo_timer = std::chrono::duration_cast<std::chrono::microseconds>(echo_end-echo_start);
    if (echo_timer.count() > 3000) {
      std::cout << "Timeout waiting for echo start" << "\n";
      break;
    }
  }
  
  while (gpioRead(echo) == 1) {
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
  double calibration_factor = -3.5;
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

 // std::cout << "Distance: " << distance << " cm" << "\n";
  //std::cout << "Average Distance (last 0.5s): " << average_distance << " cm" << "\n";
  
 //std::this_thread::sleep_for(std::chrono::milliseconds(20));
  
  return average_distance;
  
}


