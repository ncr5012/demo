# Nick Rackley's demo repository

This repository is to serve as a demonstration of Nick Rackley's full-stack robotics development experience. Files include C++ firmware for cameras, ultrasonic sensors, motor controllers, speakers and Python computer vision software that detects faces, analyzes their emotions if a face is detected, and creates popup windows to debug the overall system. 

NOTE: Select files deemed core IP are omitted (the core deep reinforcement learning loop and heavily modified FogROS2 cloud deployment software). A demo could be performed on request. 


All relevant source code is in the "jaybot" folder. The /jaybot/src folder has the c++ firmware and /jaybot/scripts has the python reinforcment learning / facial detection software.

All development was conducted by Nick Rackley, aided by chatGPT-4. 

# Demo videos:

1. https://youtu.be/BLXDSJCqv4M - A demo of the robot operating in "local" mode where my macbook pro serves as the server. It's a slow watch, becuase the robot is completely uninitialized and learning about the world from scratch with less knowledge then a new born baby, but keep in mind in about 20 minutes it demonstrates a machine that realizes Alan Turing's dream of “... a machine that can learn from experience”. Around 17:45 is where its starts to demonstrate emergent levels of intelligence (child like curiosity). 
2.  https://youtu.be/s_h7Naehl7I - Unrelated to the code above, but shown to demonstrate ability to integrate physical sensors with mobile apps - a demo video of a simple "sound alarm on motion detection" home security system I made for a mobile app development final project. (Displays mobile app development - cloud integration - physical sensor integration skills)
