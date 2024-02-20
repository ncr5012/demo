#!/bin/bash
ssh rlbot@192.168.0.15 "cd jay_ws; source install/setup.bash; sudo pigpiod; cd src/jaybot/launch; ros2 launch jaybotv1_rlbot.py
source /home/rlcontrol/jay_wsinstall/setup.bash
ros2 launch /home/rlcontrol/jay_ws/jaybot/launch/
