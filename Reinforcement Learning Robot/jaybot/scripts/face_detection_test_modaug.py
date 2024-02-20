#!/usr/bin/env python3
from asyncio.format_helpers import _format_callback_source
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import numpy as np
import dlib
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

        #self.cnn_face_detector = dlib.cnn_face_detection_model_v1('/home/rlcontrol/jay_ws/jaybot/scripts/mmod_human_face_detector.dat')
        self.face_detector = dlib.get_frontal_face_detector()
        self.landmark_predictor = dlib.shape_predictor('/home/rlcontrol/jay_ws/jaybot/scripts/shape_predictor_68_face_landmarks_GTX.dat') # You must have this file

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

        faces = self.face_detector(rgb_frame)
        
        if faces:
            mmod_rect = faces[0]
            rect = dlib.rectangle(mmod_rect.left(), mmod_rect.top(), mmod_rect.right(), mmod_rect.bottom())
            landmarks = self.landmark_predictor(rgb_frame, rect)

            # Points for eyes
            left_eye = ((landmarks.part(36).x + landmarks.part(39).x) // 2, (landmarks.part(36).y + landmarks.part(39).y) // 2)
            right_eye = ((landmarks.part(42).x + landmarks.part(45).x) // 2, (landmarks.part(42).y + landmarks.part(45).y) // 2)

            # Compute angle
            dY = right_eye[1] - left_eye[1]
            dX = right_eye[0] - left_eye[0]
            angle = np.degrees(np.arctan2(dY, dX))

            # Compute center for rotation
            eyes_center = ((left_eye[0] + right_eye[0]) // 2, (left_eye[1] + right_eye[1]) // 2)

            # Get rotation matrix
            M = cv2.getRotationMatrix2D(eyes_center, angle, scale=1)

            # Perform rotation
            aligned_rgb_frame = cv2.warpAffine(rgb_frame, M, (frame.shape[1], frame.shape[0]))

            x, y, w, h = rect.left(), rect.top(), rect.width(), rect.height()
            cropped_frame_320 = aligned_rgb_frame[max(y, 0):min(y + h, 480), max(x, 0):min(x + w, 640)]

            # Draw rectangle on the original frame
            cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)
            self.results[window_name]['face_detected'] = True
            second_results = DeepFace.analyze(cropped_frame_320, actions=['emotion'], enforce_detection=False, silent=True)

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

        
        else:
            self.results[window_name]['face_detected'] = False
            self.results[window_name]['emotions'] = None
            
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
