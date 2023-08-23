#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    # Nodes to run on the laptop
    laptop_node_1 = Node(package='jaybot', executable='rl_server', output='screen')
    laptop_node_2 = Node(package='jaybot', executable='face_detection_test.py', output='screen')
    laptop_node_3 = Node(package='jaybot', executable='rl_mind.py', output='screen')

    return LaunchDescription([
        laptop_node_1,
        laptop_node_2,
        laptop_node_3,
    ])
