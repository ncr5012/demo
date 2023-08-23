#!/usr/bin/env python3
from asyncio.format_helpers import _format_callback_source
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import numpy as np
import cv2
from deepface import DeepFace
from collections import deque
import time
from rl_custom_messages.srv import ImageService
from rl_custom_messages.srv import EmotionService  # Import your new service
import json

class ImageDisplayNode(Node):
    def __init__(self):
        super().__init__('image_display_node')
        self.srv = self.create_service(EmotionService, 'emotion_service', self.emotion_service_callback)
        self.declare_parameter('camera_service_0', '/get_image_data_camera_image_0')
        self.declare_parameter('camera_service_1', '/get_image_data_camera_image_1')

        self.client0_ = self.create_client(
            ImageService,
            self.get_parameter('camera_service_0').value)

        self.client1_ = self.create_client(
            ImageService,
            self.get_parameter('camera_service_1').value)

        self.emotion_deque = deque(maxlen=30) # assuming 30 frames per second
        self.timer0 = self.create_timer(0.033, self.timer_callback_0)
        self.timer1 = self.create_timer(0.033, self.timer_callback_1)
        self.results = {'Video Feed 0': {'face_detected': False, 'emotions': None},
                        'Video Feed 1': {'face_detected': False, 'emotions': None}}

    def emotion_service_callback(self, request, response):
        response.results = json.dumps(self.results)
        return response

    def timer_callback_0(self):
        req = ImageService.Request()
        self.client0_.call_async(req).add_done_callback(self.service_response_callback_0)

    def timer_callback_1(self):
        req = ImageService.Request()
        self.client1_.call_async(req).add_done_callback(self.service_response_callback_1)

    def service_response_callback_0(self, future):
        msg = future.result()
        np_arr = np.frombuffer(msg.image_data.data, np.uint8)
        if np_arr.size > 0:
            frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
            self.analyze_frame(frame, 'Video Feed 0')

    def service_response_callback_1(self, future):
        msg = future.result()
        np_arr = np.frombuffer(msg.image_data.data, np.uint8)
        if np_arr.size > 0:
            frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
            self.analyze_frame(frame, 'Video Feed 1')

    def analyze_frame(self, frame, window_name):
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = DeepFace.analyze(rgb_frame, actions=['emotion'], enforce_detection=False, silent=True)
        if isinstance(results, list):
            for result in results:
                x, y, w, h = result['region']['x'], result['region']['y'], result['region']['w'], result['region']['h']
                if x == 0 and y == 0:
                    self.results[window_name]['face_detected'] = False
                    self.results[window_name]['emotions'] = None
                else:
                    cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
                    self.results[window_name]['face_detected'] = True
                    center_x, center_y = x + w // 2, y + h // 2
                    cropped_frame = rgb_frame[max(center_y - 76, 0):min(center_y + 76, 480),
                                              max(center_x - 76, 0):min(center_x + 76, 640)]
                    confirmation_results = DeepFace.analyze(cropped_frame, actions=['emotion'], enforce_detection=False, silent=True)
                    if isinstance(confirmation_results, list):
                        for confirmation_result in confirmation_results:
                            x, y, w, h = confirmation_result['region']['x'], confirmation_result['region']['y'], confirmation_result['region']['w'], confirmation_result['region']['h']
                            if x == 0 and y == 0:
                                #play with this to make sure origional window face detect goes away
                                self.results[window_name]['face_detected'] = False
                                self.results[window_name]['emotions'] = None
                            else:
                                cv2.rectangle(cropped_frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
                                self.results[window_name]['face_detected'] = True
                                self.emotion_deque.append((time.time(), confirmation_result['emotion']))
                                one_second_ago = time.time() - 1
                                recent_emotions = [emotions for timestamp, emotions in self.emotion_deque if timestamp >= one_second_ago]
                                if recent_emotions:
                                    average_emotions = {emotion: round(np.mean([emo[emotion] for emo in recent_emotions])) for emotion in recent_emotions[0]}
                                    self.results[window_name]['emotions'] = average_emotions
                            
                    else:
                        self.results[window_name]['face_detected'] = False
                        self.results[window_name]['emotions'] = None

                    cv2.imshow(window_name + " Confirmation", cropped_frame)
            
            cv2.imshow(window_name, frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                cv2.destroyAllWindows()

def main(args=None):
    rclpy.init(args=args)
    image_display_node = ImageDisplayNode()
    rclpy.spin(image_display_node)
    image_display_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
