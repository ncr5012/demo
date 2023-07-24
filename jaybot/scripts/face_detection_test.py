#!/usr/bin/env python3
import cv2
from deepface import DeepFace
from collections import deque
import time
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
from cv_bridge import CvBridge
import threading

class FacialDetectionSubscriber(Node):
    def __init__(self, camera_id):
        super().__init__('facial_detection_subscriber_' + camera_id)
        self.camera_id = camera_id
        self.bridge = CvBridge()
        self.emotion_deque = deque(maxlen=15) # assuming 30 frames per second
        self.cv_window = cv2.namedWindow('Video Feed ' + camera_id, cv2.WINDOW_AUTOSIZE)
        self.subscription = self.create_subscription(CompressedImage, 'camera_image_' + camera_id, self.topic_callback, 10)
        self.frame = None
        self.display_thread = threading.Thread(target=self.display_image)
        self.display_thread.start()

    def topic_callback(self, msg):
        np_arr = np.frombuffer(msg.data, dtype=np.uint8)
        frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

        if frame is None:
            self.get_logger().error('Could not decode image data from Camera ' + self.camera_id)
            return

        # Convert to RGB for DeepFace
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # Detect emotions in the frame
        results = DeepFace.analyze(rgb_frame, actions = ['emotion'], enforce_detection=False)

        self.frame = frame  # moved this line before checking for face detection

        # Check if any face is detected
        if 'region' in results and all(key in results['region'] for key in ['x', 'y', 'w', 'h']):
            x, y, w, h = results['region']['x'], results['region']['y'], results['region']['w'], results['region']['h']
            cv2.rectangle(self.frame, (x, y), (x+w, y+h), (255, 0, 0), 2)  # Draw a rectangle around the face

            # Append current timestamp and emotion data to deque
            self.emotion_deque.append((time.time(), results['emotion']))

            # Compute the average of each emotion over the last 1 second
            one_second_ago = time.time() - 1
            recent_emotions = [emotions for timestamp, emotions in self.emotion_deque if timestamp >= one_second_ago]
            if recent_emotions:
                average_emotions = {emotion: round(np.mean([emo[emotion] for emo in recent_emotions])) for emotion in recent_emotions[0]}
                self.get_logger().info('Camera ' + self.camera_id + ' average emotions: ' + str(average_emotions))
        else:
            self.get_logger().info('No face detected in Camera ' + self.camera_id)

    def display_image(self):
        while rclpy.ok():
            if self.frame is not None:
                cv2.imshow('Video Feed ' + self.camera_id, self.frame)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    facial_detection_subscriber_0 = FacialDetectionSubscriber('0')
    facial_detection_subscriber_1 = FacialDetectionSubscriber('1')

    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(facial_detection_subscriber_0)
    executor.add_node(facial_detection_subscriber_1)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        if facial_detection_subscriber_0.display_thread.is_alive():
            facial_detection_subscriber_0.display_thread.join()
        if facial_detection_subscriber_1.display_thread.is_alive():
            facial_detection_subscriber_1.display_thread.join()

        facial_detection_subscriber_0.destroy_node()
        facial_detection_subscriber_1.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
