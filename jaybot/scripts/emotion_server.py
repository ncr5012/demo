#!/usr/bin/env python3
import rclpy
import json
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import numpy as np
import cv2
from deepface import DeepFace
from collections import deque
import time
from rl_custom_messages.srv import ImageService
from rl_custom_messages.srv import EmotionService

class ImageDisplayNode(Node):
    def __init__(self):
        super().__init__('image_display_node')
        self.declare_parameter('camera_service_0', '/get_image_data_camera_image_0')
        self.declare_parameter('camera_service_1', '/get_image_data_camera_image_1')

        self.client0_ = self.create_client(
            ImageService,
            self.get_parameter('camera_service_0').value)

        self.client1_ = self.create_client(
            ImageService,
            self.get_parameter('camera_service_1').value)

        self.emotion_deque = deque(maxlen=30) # assuming 30 frames per second
        self.latest_average_emotions = {}

        self.timer0 = self.create_timer(0.033, self.timer_callback_0)
        self.timer1 = self.create_timer(0.033, self.timer_callback_1)

        # Create the service
        self.srv = self.create_service(EmotionService, 'emotion_service', self.emotion_service_callback)
        
    def timer_callback_0(self):
        req = ImageService.Request()
        self.client0_.call_async(req).add_done_callback(self.service_response_callback_0)

    def timer_callback_1(self):
        req = ImageService.Request()
        self.client1_.call_async(req).add_done_callback(self.service_response_callback_1)

    def service_response_callback_0(self, future):
        msg = future.result()
        np_arr = np.frombuffer(msg.image_data.data, np.uint8)
        frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
        self.latest_average_emotions['Video Feed 0'] = self.analyze_frame(frame, 'Video Feed 0')

    def service_response_callback_1(self, future):
        msg = future.result()
        np_arr = np.frombuffer(msg.image_data.data, np.uint8)
        frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
        self.latest_average_emotions['Video Feed 1'] = self.analyze_frame(frame, 'Video Feed 1')

    def analyze_frame(self, frame, window_name):
        # Convert to RGB for DeepFace
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # Detect emotions in the frame
        results = DeepFace.analyze(rgb_frame, actions = ['emotion'], enforce_detection = False)
        average_emotions = None

        results = [results] if isinstance(results, dict) else results

        for result in results:
            x, y, w, h = result['region']['x'], result['region']['y'], result['region']['w'], result['region']['h']
            if x == 0 and y == 0:
                print("No face detected")
            else:
                cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)  # Draw a rectangle around the face

                # Append current timestamp, source, and emotion data to deque
                self.emotion_deque.append((time.time(), {"source": window_name, "emotion": result}))

                # Compute the average of each emotion over the last 1 second
                one_second_ago = time.time() - 1
                recent_emotions = [emotions for timestamp, emotions in self.emotion_deque if timestamp >= one_second_ago]
                if recent_emotions and isinstance(recent_emotions[0], tuple) and isinstance(recent_emotions[0][1], dict) and 'emotion' in recent_emotions[0][1]:
                    average_emotions = {emotion: round(np.mean([emo[1]['emotion'][emotion] for emo in recent_emotions if isinstance(emo[1], dict) and 'emotion' in emo[1]])) for emotion in recent_emotions[0][1]['emotion']}
                    print(average_emotions)

        # Show the frame with any detected faces highlighted
        cv2.imshow(window_name, frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            cv2.destroyAllWindows()

        return average_emotions

    def emotion_service_callback(self, request, response):
        # Check if faces were detected in the last frame from each camera
        camera1_face_detected = any(result[1]['emotion']['region']['x'] != 0 and result[1]['emotion']['region']['y'] != 0 for result in self.emotion_deque if result[1]['source'] == 'Video Feed 0')
        camera2_face_detected = any(result[1]['emotion']['region']['x'] != 0 and result[1]['emotion']['region']['y'] != 0 for result in self.emotion_deque if result[1]['source'] == 'Video Feed 1')
        
        # Extract the emotion data from the last frame from each camera
        camera1_emotions = self.latest_average_emotions.get('Video Feed 0', None)
        camera2_emotions = self.latest_average_emotions.get('Video Feed 1', None)
        
        # Set the response
        response.camera1_face_detected = camera1_face_detected
        response.camera1_emotions_json = json.dumps(camera1_emotions)
        response.camera2_face_detected = camera2_face_detected
        response.camera2_emotions_json = json.dumps(camera2_emotions)
        
        return response

def main(args=None):
    rclpy.init(args=args)
    image_display_node = ImageDisplayNode()
    rclpy.spin(image_display_node)
    image_display_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

