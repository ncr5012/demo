#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import os
import datetime
import time

class MonitorNode(Node):
    def __init__(self):
        super().__init__('monitor_node')
        self.robot_nodes = ['/motor_controller_node', '/range_publisher']  # replace these with your actual robot node names
        self.start_time = time.time()
        self.timer = self.create_timer(1.0, self.check_nodes)  # check every second

    def check_nodes(self):
        active_nodes = self.get_node_names()

        for node in self.robot_nodes:
            if node not in active_nodes:
                self.get_logger().info('Node {} has shut down'.format(node))
                self.log_timestamp()
                self.shutdown_system()

    def log_timestamp(self):
        timestamp = datetime.datetime.now()
        duration = time.time() - self.start_time
        self.get_logger().info('Timestamp: {}'.format(timestamp))
        self.get_logger().info('Program duration: {}'.format(duration))

    def shutdown_system(self):
        self.get_logger().info('Shutting down the system...')
        os.system('ros2 daemon stop')
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = MonitorNode()
    rclpy.spin(node)

if __name__ == '__main__':
    main()
