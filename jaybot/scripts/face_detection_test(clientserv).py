#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import numpy as np
import cv2
from deepface import DeepFace
from collections import deque
import time
from rl_custom_messages.srv import ImageService
from rl_custom_messages.srv import EmotionService
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

        self.emotion_deque = deque(maxlen=30)  # assuming 30 frames per second
        self.results = {'Video Feed 0': {'face_detected': False, 'emotions': None},
                        'Video Feed 1': {'face_detected': False, 'emotions': None}}

    def emotion_service_callback(self, request, response):
        # Trigger both clients
        self.get_frame_from_remote_server('Video Feed 0')
        self.get_frame_from_remote_server('Video Feed 1')
        response.results = json.dumps(self.results)
        return response

    def get_frame_from_remote_server(self, window_name):
        client = self.client0_ if window_name == 'Video Feed 0' else self.client1_
        req = ImageService.Request()
        client.call_async(req).add_done_callback(lambda future: self.service_response_callback(future, window_name))

    def service_response_callback(self, future, window_name):
        msg = future.result()
        np_arr = np.frombuffer(msg.image_data.data, np.uint8)
        if np_arr.size > 0:
            frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
            self.analyze_frame(frame, window_name)

    def analyze_frame(self, frame, window_name):
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = DeepFace.analyze(rgb_frame, actions=['emotion'], enforce_detection=False, silent=True, detector_backend='mediapipe')
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
                    cropped_frame_320 = rgb_frame[max(center_y - 120, 0):min(center_y + 120, 480),
                                                max(center_x - 160, 0):min(center_x + 160, 640)]
                    second_results = DeepFace.analyze(cropped_frame_320, actions=['emotion'], enforce_detection=False, silent=True, detector_backend='mediapipe')

                    if isinstance(second_results, list):
                        for second_result in second_results:
                            x, y, w, h = second_result['region']['x'], second_result['region']['y'], second_result['region']['w'], second_result['region']['h']
                            if x == 0 and y == 0:
                                self.results[window_name]['face_detected'] = False
                                self.results[window_name]['emotions'] = None
                            else:
                                cv2.rectangle(cropped_frame_320, (x, y), (x + w, y + h), (255, 0, 0), 2)
                                center_x, center_y = x + w // 2, y + h // 2
                                cropped_frame_152 = cropped_frame_320[max(center_y - 76, 0):min(center_y + 76, 240),
                                                                    max(center_x - 76, 0):min(center_x + 76, 320)]
                                confirmation_results = DeepFace.analyze(cropped_frame_152, actions=['emotion'], enforce_detection=False, silent=True)
                                for confirmation_result in confirmation_results:
                                    x, y, w, h = confirmation_result['region']['x'], confirmation_result['region']['y'], confirmation_result['region']['w'], confirmation_result['region']['h']
                                    self.emotion_deque.append((time.time(), confirmation_result['emotion']))
                                    one_second_ago = time.time() - 1
                                    recent_emotions = [emotions for timestamp, emotions in self.emotion_deque if timestamp >= one_second_ago]
                                    if recent_emotions:
                                        average_emotions = {emotion: round(np.mean([emo[emotion] for emo in recent_emotions])) for emotion in recent_emotions[0]}
                                        self.results[window_name]['emotions'] = average_emotions

                                results_top_text = "angry: " + str(self.results[window_name]['emotions']['angry']) + " disgust: " + str(self.results[window_name]['emotions']['disgust']) + " fear: " + str(self.results[window_name]['emotions']['fear'])
                                results_bottom_text = "happy: " + str(self.results[window_name]['emotions']['happy']) + " sad: " + str(self.results[window_name]['emotions']['sad']) + " surprise: " + str(self.results[window_name]['emotions']['surprise'])
                                font_scale = .6
                                color = (0, 165, 255)
                                thickness = 2
                                cv2.putText(cropped_frame_320, results_top_text, (5, 30), cv2.FONT_HERSHEY_SIMPLEX, font_scale, color, thickness)
                                cv2.putText(cropped_frame_320, results_bottom_text, (5, 210), cv2.FONT_HERSHEY_SIMPLEX, font_scale, color, thickness)

                    
                    else:
                        self.results[window_name]['face_detected'] = False
                        self.results[window_name]['emotions'] = None
                    
                    cv2.imshow(window_name + " Confirmation", cropped_frame_320)
            
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