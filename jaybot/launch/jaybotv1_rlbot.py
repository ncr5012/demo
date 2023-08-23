#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    # Nodes to run on the robot
    #Note, need to figure out how to automattically send sudo pigpiod
    robot_node_1 = Node(
        package='jaybot',
        executable='camera_publisher',
    )

    robot_node_2 = Node(
        package='jaybot',
        executable='range_publisher',
    )

    robot_node_3 = Node(
        package='jaybot',
        executable='motor_controller',
    )

    robot_node_4 = Node(
        package='jaybot',
        executable='speaker_controller',
    )

    return LaunchDescription([
        robot_node_1,
        robot_node_2,
        robot_node_3,
        robot_node_4
    ])
