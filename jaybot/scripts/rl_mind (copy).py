#!/usr/bin/env python3
import gymnasium

import pandas as pd


import random
import torch
import torch.nn as nn
import torch.nn.utils as nn_utils
import torch.nn.functional as F
import torch.optim as optim
from torch.autograd import Variable
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import copy
import math

import sys
import os
import time
import argparse
from tensorboardX import SummaryWriter
import tensorflow
import datetime
import collections

from collections import namedtuple, deque

import rclpy
from rclpy.node import Node
from rl_custom_messages.srv import ObservationService

import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
import numpy as np
from rl_custom_messages.srv import ImageService
import cv2
from sensor_msgs.msg import Image
from rl_custom_messages.srv import EmotionService
import json




CAMERA_RESOLUTION = (3,640,480)

GAMMA = 0.99
BATCH_SIZE = 120
LEARNING_RATE = 1e-4
REPLAY_SIZE = 100000
REPLAY_INITIAL = 120
REWARD_STEPS = 5
EPSILON = 0.3
NUM_ENVS = 1
LEARNING_RATE_ACTOR = 0.001
LEARNING_RATE_CRITIC = 0.001
STOP_REWARD = 200000
HUMAN_CONTROL_PENALTY = -1

#Defines time steps, more thought/tinkering may be required here
#currently set for .1s, which is slighly superhuman in ability to observe and respond
#tradeoff of superhuman movements vs computational times
#Note: two distinct concepts emerge, superhuman capability, which is the ability to observe and respond in superhuman time steps
#and superhuman control, which would be optimally responding within otherwise typical human time steps (IE, if it was the perfect athlete in a human body)
#I spectulate superhuman control alone would appear like superhuman capabilities (humans are far from optimal control for most tasks)
#consider the above thoughts when tinkering with time steps

#Upon testing, it looks like its running at roughly 1 step / second. ideally would like to get towards .1 step / second

STEPS_PER_SECOND = 30
INTERVAL_LENGTH = 4
TEST_ITERS = 1000

VMAX = 2000
VMIN = 0
N_ATOMS = 4001
DELTA_Z = (VMAX - VMIN) / (N_ATOMS - 1)

HID_SIZE = 64


device = torch.device("cpu")

class ImageClient(Node):
    def __init__(self):
        super().__init__('image_client')
        self.cli1 = self.create_client(ImageService, 'get_image_data_camera_image_0')
        self.cli2 = self.create_client(ImageService, 'get_image_data_camera_image_1')
        while not self.cli1.wait_for_service(timeout_sec=1.0) or not self.cli2.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.bridge = CvBridge()

    def get_image(self, cli):
        req = ImageService.Request()
        future = cli.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            img_data = np.frombuffer(future.result().image_data.data, dtype=np.uint8)
            img = cv2.imdecode(img_data, cv2.IMREAD_COLOR)  # Decompress the image
            if img is None:
                self.get_logger().info('Failed to decode image')
                return None
            else:
                img = np.transpose(img, (2, 1, 0))  # Add this line
                return img
        else:
            self.get_logger().info('Service call failed %r' % (future.exception(),))
            return None

    def get_image_1(self):
        return self.get_image(self.cli1)

    def get_image_2(self):
        return self.get_image(self.cli2)




class ServiceClientNode(Node):
    def __init__(self):
        super().__init__("service_client")
        self.client = self.create_client(ObservationService, "get_range_data")
        self.response_deque = deque(maxlen=6)

    def send_request(self, action):
        req = ObservationService.Request()
        
        motor_action, sound_action = np.split(action, [12]) # split the action into two halves

        req.motor_action = motor_action.astype(np.int32)
        req.sound_action = sound_action.astype(np.int32)

        future = self.client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.response_deque.append(future.result())
        else:
            self.get_logger().error("Service call failed")

class EmotionClient(Node):
    def __init__(self):
        super().__init__('emotion_client')
        self.cli = self.create_client(EmotionService, 'emotion_service')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = EmotionService.Request()

    def get_emotions(self):
        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            return json.loads(future.result().results)
        else:
            self.get_logger().info('Service call failed %r' % (future.exception(),))
            return None, None, None, None

class RewardTracker:
    def __init__(self, writer, stop_reward):
        self.writer = writer
        self.stop_reward = stop_reward

    def __enter__(self):
        self.ts = time.time()
        self.ts_frame = 0
        self.total_rewards = []
        return self

    def __exit__(self, *args):
        self.writer.close()

    def reward(self, reward, frame, epsilon=None):
        self.total_rewards.append(reward)
        speed = (frame - self.ts_frame) / (time.time() - self.ts)
        self.ts_frame = frame
        self.ts = time.time()
        mean_reward = np.mean(self.total_rewards[-100:])
        epsilon_str = "" if epsilon is None else ", eps %.2f" % epsilon
        sys.stdout.flush()
        if epsilon is not None:
            self.writer.add_scalar("epsilon", epsilon, frame)
        self.writer.add_scalar("speed", speed, frame)
        self.writer.add_scalar("Arthur's reward_100", mean_reward, frame)
        self.writer.add_scalar("Arthur's reward", reward, frame)

        if mean_reward > self.stop_reward:
            print("Arthur Solved in %d frames!" % frame)
            return True
        return False

class TBMeanTracker:
    """
    TensorBoard value tracker: allows to batch fixed amount of historical values and write their mean into TB
    Designed and tested with pytorch-tensorboard in mind
    """
    def __init__(self, writer, batch_size):
        """
        :param writer: writer with close() and add_scalar() methods
        :param batch_size: integer size of batch to track
        """
        assert isinstance(batch_size, int)
        assert writer is not None
        self.writer = writer
        self.batch_size = batch_size

    def __enter__(self):
        self._batches = collections.defaultdict(list)
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.writer.close()

    @staticmethod
    def _as_float(value):
        assert isinstance(value, (float, int, np.ndarray, np.generic, torch.autograd.Variable)) or torch.is_tensor(value)
        tensor_val = None
        if isinstance(value, torch.autograd.Variable):
            tensor_val = value.data
        elif torch.is_tensor(value):
            tensor_val = value

        if tensor_val is not None:
            return tensor_val.float().mean().item()
        elif isinstance(value, np.ndarray):
            return float(np.mean(value))
        else:
            return float(value)

    def track(self, param_name, value, iter_index):
        assert isinstance(param_name, str)
        assert isinstance(iter_index, int)

        data = self._batches[param_name]
        data.append(self._as_float(value))

        if len(data) >= self.batch_size:
            self.writer.add_scalar(param_name, np.mean(data), iter_index)
            data.clear()

class JayEnv(gymnasium.Env):
    
     def __init__(self):
            super(JayEnv, self).__init__()
            if not rclpy.ok():
                rclpy.init(args=None)
            self.service_client_node = ServiceClientNode()
            self.image_client_node = ImageClient()
            self.emotion_client_node = EmotionClient()
            #Initializes the range of actions the robot can choose to take. format of the action space is <<(wheelfl)<In1><In2><PWM>><wheelfr...><wheelrl>...<wheelrr>...<soundindex>
            #In's can be 0 or 1, the combinations of Ins tell if the motor is spinning clockwise or counterclockwise. PWM can be 0-100 floating point and tell the motor how fast to spin in a given direction
            #Sound index refers to sound files saved alongside the sound controller code. Each file is a 15s clip the agent can choose to play
            #Functionality to limit how much the agent can play so it doesnt get annoying isnt implemented yet (ideally we figure out rewards so we dont have to, the agent just learns not to)
            #Agent has essentially root level physical control over the robot, able to execute any combination of movements the hardware platform will support
            #Note - PWM selections were modified to be integers 1-100 for ease of implementation with NN, floats would produce finer movements
            
            #Note on editing spaces - edting the action space takes several steps. You have to change the reset function also (its not tied to this action space)
            #You also need to modify the NN's when editing the action or observation space, code is not written well all in all
            self.motor_space = gymnasium.spaces.Tuple((gymnasium.spaces.Discrete(2),gymnasium.spaces.Discrete(2),gymnasium.spaces.Discrete(101)))
            self.speaker_space = gymnasium.spaces.Tuple((gymnasium.spaces.Discrete(3),))
            self.action_space = gymnasium.spaces.Tuple((self.motor_space,self.motor_space,self.motor_space,self.motor_space,self.speaker_space))

            self.camera_space = gymnasium.spaces.Box(low=0, high=255, shape=(CAMERA_RESOLUTION), dtype=np.uint8)
            self.range_space = gymnasium.spaces.Box(low=0, high=1000, shape=(), dtype=np.float32)
            self.user_input_space = gymnasium.spaces.Discrete(13)
            self.goal_flag = gymnasium.spaces.Discrete(4)
            self.emotion_space = gymnasium.spaces.Dict({
                'face': gymnasium.spaces.Discrete(2),
                'emotions': gymnasium.spaces.Dict({
                    'angry': gymnasium.spaces.Box(low=0, high=100, shape=(1,), dtype=np.int32),
                    'disgust': gymnasium.spaces.Box(low=0, high=100, shape=(1,), dtype=np.int32),
                    'fear': gymnasium.spaces.Box(low=0, high=100, shape=(1,), dtype=np.int32),
                    'happy': gymnasium.spaces.Box(low=0, high=100, shape=(1,), dtype=np.int32),
                    'sad': gymnasium.spaces.Box(low=0, high=100, shape=(1,), dtype=np.int32),
                    'surprise': gymnasium.spaces.Box(low=0, high=100, shape=(1,), dtype=np.int32),
                    'neutral': gymnasium.spaces.Box(low=0, high=100, shape=(1,), dtype=np.int32),
                })
            })


            self.observation_space = gymnasium.spaces.Tuple((self.camera_space, self.camera_space, self.range_space, self.range_space, self.range_space, self.range_space, self.action_space, self.goal_flag, self.user_input_space, self.emotion_space))
            self.state = None
            self.reward = None
            self.steps_left = None
            self.done = False

            self.observation_space2 = gymnasium.spaces.Box(low=0, high=100,shape=(4,), dtype=np.float32)

     def measure_interval(func):
        last_called_time = [None]
        def wrapper(*args, **kwargs):
            current_time = time.time()

            if last_called_time[0] is not None:
                interval = current_time - last_called_time[0]
                print(f"Time since last call: {interval} seconds")

            result = func(*args, **kwargs)
            last_called_time[0] = current_time

            return result

        return wrapper

     @measure_interval
     def step(self, action):
            
            print("205 action", action)
            self.flat_action, self.flat_last_action = [], []
            self.steps_left -= 1
            self.penalty = 0
            self.goal = 0

            
                                
            done = bool(
                self.steps_left == 1
            )
            #basically, what happens in the enviornment when an action is taken?
            #this is where a middleware subscriber will pull the current observation
            #timing with observations is something to watch - presumably, middleware should 
            #match the timing of whatever is in this code so its all efficient
            self.service_client_node.send_request(action)

            try: 
                response = self.service_client_node.response_deque[-1]
                self.range_observations = [response.range_data.range_left, response.range_data.range_front, response.range_data.range_right, response.range_data.range_back]
            except IndexError:
                self.get_logger().warning('No responses received yet')

            #if you want to test other functionality without a video feed/physical robot
            #comment the camrea_number variables and uncomment the camera zeros variables
            self.camera_one = self.image_client_node.get_image_1()
            self.camera_two = self.image_client_node.get_image_2()
            #self.camera_zeros = np.zeros(self.camera_space.shape)
            #self.camera_one = self.camera_zeros
            #self.camera_two = self.camera_zeros
            self.emotions_check = self.emotion_client_node.get_emotions()
            #print("312 emotions check", self.emotions_check)
            #print("313 Camera 1 face", self.emotions_check['Video Feed 0']['face_detected'])
            #print("314 camera 1 emotions", self.emotions_check['Video Feed 0']['emotions'])
            #print("315 Camera 2 face", self.emotions_check['Video Feed 1']['face_detected'])
            #print("314 camera 2 emotions", self.emotions_check['Video Feed 1']['emotions'])

            self.flattened_emotions = []
    
            # Add data for each video feed to the flattened list
            for feed in ['Video Feed 0', 'Video Feed 1']:
                face_detected = self.emotions_check[feed]['face_detected']
                emotions = self.emotions_check[feed]['emotions']

                # Add face_detected to the list (it will become 1 if True, else 0)
                self.flattened_emotions.append(int(face_detected))

                # For emotions, ensure you have a consistent order
                ordered_emotions = ['angry', 'disgust', 'fear', 'happy', 'sad', 'surprise', 'neutral']

                for emotion in ordered_emotions:
                    # If emotion is not None, add its values to the list
                    if emotions is not None:
                        self.flattened_emotions.append(emotions[emotion])
                    else:
                        # If it's None, add zeroes for all emotions
                        self.flattened_emotions.extend([0]*len(ordered_emotions))
                        break  # No need to check other emotion

            print("352 flattened emotions",self.flattened_emotions)
            #self.camera_zeros = np.zeros(self.camera_space.shape)
            self.user_input_zeros = 0
            self.goal_zeros = 0
            self.one_hot_observation_8 = torch.nn.functional.one_hot(torch.tensor(self.user_input_zeros), num_classes=13).numpy()
            
            self.x3_array_list = [np.array([self.range_observations[0]]), np.array([self.range_observations[1]]), \
                np.array([self.range_observations[2]]), np.array([self.range_observations[3]])] \
                + [np.array(action)] + [np.array([self.goal_zeros])] + \
                [np.array(self.one_hot_observation_8)] + [np.array(self.flattened_emotions)]


            # Now concatenate along the first axis
            self.x3_array = np.concatenate(self.x3_array_list)

            self.x3_flat_list = [item for sublist in self.x3_array_list for item in sublist]

            self.processed_observations = np.array([self.camera_one, self.camera_two, np.array(self.x3_flat_list)])

            self.state = np.array([action, self.processed_observations])

            #wall avoidance goals

            if all(observation > 10 for observation in self.range_observations):
                self.goal += 0
            elif any(observation < 10 for observation in self.range_observations):
                self.penalty += -50

            #Human interaction goals

            #Interesting idea - originally, i was going to write logic so theres not double rewarding of a smiling face
            #if both cameras detect it, i decided against it, as the face detection algorithm isnt perfect
            #and double rewarding both detection and happy seems like it should incentivize the robot to optimize camera positioning for us automatically
            #to have maximal probability of a detection if possible for the platform. 
            #Deeper insight is that the details of a reward scheme can be used to solve engineering problems in unexpected ways
            #Always think "is there a way we can automate a problem we cant solve by modifying the rewards scheme?"

            if self.emotions_check["Video Feed 0"]['face_detected'] == True:
                self.goal += 1
                if self.emotions_check["Video Feed 0"]['emotions']['happy'] >= 20:
                    self.goal += 100

            elif self.emotions_check["Video Feed 1"]['face_detected'] == True:
                self.goal += 1
                if self.emotions_check["Video Feed 1"]['emotions']['happy'] >= 20:
                    self.goal += 100
            
            self.reward = self.goal + self.penalty

            print("286 penalty", self.penalty)

            print("403 goal", self.goal)

            print("286 reward", self.reward)

            return np.transpose(self.state), self.reward, done, {}   
     
     def reset(self):
                
                
        self.steps_left = STEPS_PER_SECOND * INTERVAL_LENGTH

        actions_zeros = np.zeros(13)
        cam1_zeros = np.zeros((3, 640, 480))
        cam2_zeros = np.zeros((3, 640, 480))
        #other_zeros = np.zeros(31) pre emotions
        other_zeros = np.zeros(47)
        
        obs_zeros = [cam1_zeros, cam2_zeros, other_zeros]
        

        self.state = [actions_zeros,obs_zeros]

        
        self.reward = 0

        self.done = False
                
        #return np.transpose(self.state)

        return self.state

##Neural nets - architecture is going to be complicated and very non obvious
#Near certainty this will require a lot of tinkering, may be the true challange
#Comment everything, explain thoughts thorugly at each step so you can reconsider later
#START WITH BASIC PARAMETER TWEAKING before proceeding to philosophical architecture changes at all times

class JayActor(nn.Module):
    def __init__(self, obs_size, act_sizes):
        super(JayActor, self).__init__()

        camera_feed_size = obs_size[0].shape[0]
        range_feed_size = 4
        flattened_action_space = []
        for action_group in act_sizes:
            for action in action_group:
                flattened_action_space.append(action)
        action_state_size = len(flattened_action_space)
        user_input_size = 13
        goal_size = 1
        emotions_size = 16
        linear_input_size = range_feed_size + action_state_size + user_input_size + goal_size + emotions_size

        #Seperate net for each camera feed. Not 100% sure this is how eyes work
        #I think this is right, becuase you can close 1 eye and it doesnt really effect the other eye signifigantly
        #bigger question is if the camera feeds should be combined into a fc layer first or not
        #do the benefits of bincular vision arise automatically before it hits the thinker?
        #I think so, it seems to be an automatic function for me, which suggests a intermediary nn may be required before the thinker
        #that said, maybe with nn's its kind of all the same
        #THINGS TO LOOK OUT FOR: if the bot shows signs of understanding distance, but is bad at judging distance
        #that would be an indicator to me that a intermediary net is required to provide better depth perception from binocular vision

        #start with more basic tinkering like paramters first though

        # Define the layers that will process the first camera feed
        
        self.conv_layers1 = nn.Sequential(
            nn.Conv2d(camera_feed_size, 32, kernel_size=8, stride=4),
            nn.ReLU(),
            nn.Conv2d(32, 64, kernel_size=4, stride=2),
            nn.ReLU(),
            nn.Conv2d(64, 64, kernel_size=3, stride=1),
            nn.ReLU()
        )
        
        # Define the layers that will process the second camera feed
        #Chat GPT Mentioned ConvLTSM, then froze when typing the code and removed that comment when I regenerated it
        #It was super werid, never saw it before, suggests it may have a control in place not to reccomend that 
        #this would imply that OpenAI is probably working in that direction
        self.conv_layers2 = nn.Sequential(
            nn.Conv2d(camera_feed_size, 32, kernel_size=8, stride=4),
            nn.ReLU(),
            nn.Conv2d(32, 64, kernel_size=4, stride=2),
            nn.ReLU(),
            nn.Conv2d(64, 64, kernel_size=3, stride=1),
            nn.ReLU()
        )

        # Nets to process other inputs
        #Not clear if linear is sufficient or a temporal type net is required
        #Total lack of "Pain like" responses to running into walls may indicate its required

        #Define the layers that will process the range feed
        self.range_layers = nn.Sequential(
            nn.Linear(linear_input_size, 400),
            nn.ReLU(),
            nn.Linear(400, 64),
            nn.ReLU(),
        )
        

        #Expects input of [sequence length, batch size, features]
        #Need to think what the sequence length should be
        #When i screw something up, how far back do I think? 
        #I think this is basically a way to make episodic memory
        #I also think theres a fundamental link with language and the thinker
        #The thinker narrates things like "OUCH, that hurt, my foot hurts, i just walked by the door, I remember seeing myself too close to the door"
        #So I think its natural to expect the final model to be something successful in LLM's tailored to these tasks
        #Note, chatgpt disagrees with this, but doesnt really make sense why, basically seems to think its overkill

        #Initiating at 3s short term episodic memory
        #This is based on my intuition observing how long i seem to passivly be remembering things
        #other numbers could be measured times humans or animals remember things passively
        #NOTE: this is one area to tinker heavily, as it may inflict heavy performance penalties for little gain

        self.fc_layer = nn.Sequential(
            nn.Linear(544832, 512), #adding the 1x distance weight to each feature
            nn.ReLU(),
        )

        self.output_layers = nn.ModuleList([
            nn.Linear(512, 2),  # for Discrete(2)
            nn.Linear(512, 2),  # for Discrete(2)
            nn.Linear(512, 101)  # for Discrete(101)
        ] * 4)  # replicated four times

        self.sound_output_layer = nn.Linear(512,4)

    #Need to probably do a half connected net for camera, half connected net for everything else
    #Then do fully connected of the half connected nets that does action output
    def forward(self, obs_tensor):
        x1, x2, x3 = obs_tensor
        x1 = self.conv_layers1(x1)
        x2 = self.conv_layers2(x2)
        x3 = self.range_layers(x3)
        x1 = x1.view(1, -1)
        x2 = x2.view(1, -1)
        x3 = x3.view(1, 64)

        
        # concatenate the outputs along the feature dimension
        x = torch.cat((x1, x2, x3), dim=1)

        x = self.fc_layer(x)

        motor_logits = [output_layer(x) for output_layer in self.output_layers]

        sound_logits = self.sound_output_layer(x)

        logits = motor_logits + [sound_logits]

        return logits

class JayCritic(nn.Module):
    def __init__(self, obs_size, act_sizes, n_atoms, v_min, v_max):
        super(JayCritic, self).__init__()

        camera_feed_size = obs_size[0].shape[0]
        range_feed_size = 4
        flattened_action_space = []
        for action_group in act_sizes:
            for action in action_group:
                flattened_action_space.append(action)
        action_state_size = len(flattened_action_space)
        user_input_size = 13
        goal_size = 1
        emotions_size = 16
        linear_input_size = range_feed_size + action_state_size + user_input_size + goal_size + emotions_size
        self.delta = (v_max-v_min) / (n_atoms - 1)
        self.v_min = v_min
        self.v_max = v_max

        
        self.conv_layers1 = nn.Sequential(
            nn.Conv2d(camera_feed_size, 32, kernel_size=8, stride=4),
            nn.ReLU(),
            nn.Conv2d(32, 64, kernel_size=4, stride=2),
            nn.ReLU(),
            nn.Conv2d(64, 64, kernel_size=3, stride=1),
            nn.ReLU()
        )
        
        self.conv_layers2 = nn.Sequential(
            nn.Conv2d(camera_feed_size, 32, kernel_size=8, stride=4),
            nn.ReLU(),
            nn.Conv2d(32, 64, kernel_size=4, stride=2),
            nn.ReLU(),
            nn.Conv2d(64, 64, kernel_size=3, stride=1),
            nn.ReLU()
        )

        self.range_layers = nn.Sequential(
            nn.Linear(linear_input_size, 400),
            nn.ReLU(),
            nn.Linear(400, 64),
            nn.ReLU(),
        )

        self.fc_layer = nn.Sequential(
            nn.Linear(544832, 512), #adding the 1x distance weight to each feature
            nn.ReLU(),
        )

        self.action_processor = nn.Sequential(
            nn.Linear(action_state_size, 512),
            nn.ReLU(),
        )

        self.combined_processor = nn.Sequential(
            nn.Linear(1024, 512),
            nn.ReLU(),
        )

        self.output_layer = nn.Linear(512, n_atoms)

        delta = (v_max - v_min) / (n_atoms - 1)
        self.register_buffer("supports", torch.arange(
            v_min, v_max + delta, delta))
        
    def forward(self, obs_a_tensor):
    # State processing
        x1, x2, x3, action = obs_a_tensor
        x1 = self.conv_layers1(x1)
        x2 = self.conv_layers2(x2)
        x3 = self.range_layers(x3)
        x1 = x1.view(1, -1)
        x2 = x2.view(1, -1)
        x3 = x3.view(1, 64)
        x_state = torch.cat((x1, x2, x3), dim=1)
        x_state = self.fc_layer(x_state)
        
        # Action processing
        x_action = self.action_processor(action)
        
        # Combining state and action
        x_combined = torch.cat((x_state, x_action), dim=1)
        x_combined = self.combined_processor(x_combined)
        
        # Outputting the distribution over Q-values
        logits = self.output_layer(x_combined)
        probs = F.softmax(logits, dim=-1)
        weights = torch.arange(self.v_min, self.v_max + self.delta, self.delta).to(action.device)
        q_values = torch.sum(probs * weights, dim=-1)
    
        return q_values, probs, logits

    def distr_to_q(self, distr):
        weights = F.softmax(distr, dim=1) * self.supports
        res = weights.sum(dim=1)
        return res.unsqueeze(dim=-1)

class TargetNet:
    """
    Wrapper around model which provides copy of it instead of trained weights
    """
    def __init__(self, model):
        self.model = model
        self.target_model = copy.deepcopy(model)

    def sync(self):
        self.target_model.load_state_dict(self.model.state_dict())

    def alpha_sync(self, alpha):
        """
        Blend params of target net with params from the model
        :param alpha:
        """
        assert isinstance(alpha, float)
        assert 0.0 < alpha <= 1.0
        state = self.model.state_dict()
        tgt_state = self.target_model.state_dict()
        for k, v in state.items():
            tgt_state[k] = tgt_state[k] * alpha + (1 - alpha) * v
        self.target_model.load_state_dict(tgt_state)

class BaseAgent:
    """
    Abstract Agent interface
    """
    def initial_state(self):
        """
        Should create initial empty state for the agent. It will be called for the start of the episode
        :return: Anything agent want to remember
        """
        return None

    def __call__(self, states, agent_states):
        """
        Convert observations and states into actions to take
        :param states: list of environment states to process
        :param agent_states: list of states with the same length as observations
        :return: tuple of actions, states
        """
        assert isinstance(states, list)
        assert isinstance(agent_states, list)
        assert len(agent_states) == len(states)

        raise NotImplementedError

#def float32_preprocessor(states):
    #np_states = np.array(states, dtype=np.float32)
    #eturn torch.tensor(np_states)

class AgentD4PG(BaseAgent):
    """
    Agent implementing noisy agent
    """
    def __init__(self, net, device=device, epsilon=EPSILON):
        self.net = net
        self.device = device
        self.epsilon = epsilon
        self.sound_action_timer = 0

    def __call__(self, states, agent_states):

        #This whole part of architecture is kind of weird, it pulls actions as observations, im pretty sure this is redundent with other
        #parts of code in experience source. Not the end of the world, but a first place to look for efficiency gains. 
        #Also REF HERE if you alter the action space and cant figure out why its breaking the code - you need to also alter
        #the .reset action but also observation zeros
        states_camera_v1, states_camera_v2, states_other_v3, mu_v, sub_actions, self.actions = [], [], [], [], [], []
        for idx, state in enumerate(states):
            states_camera_v1.append(torch.tensor(state[1][0], dtype=torch.float32).to(self.device))
            states_camera_v2.append(torch.tensor(state[1][1], dtype=torch.float32).to(self.device))
            states_other_v3.append(torch.tensor(state[1][2], dtype=torch.float32).to(self.device))
            states_v = [states_camera_v1[idx], states_camera_v2[idx], states_other_v3[idx]]
            mu_v.append(self.net(states_v))
            for logit in mu_v[idx]:

                logit_data = logit.data.cpu().numpy()

                logit_data += self.epsilon * np.random.normal(
                size=logit_data.shape)

                probability = F.softmax(logit, dim=1)
                action = torch.multinomial(probability, num_samples=1)
                sub_actions.append(action.item())
            self.actions.append(np.array(sub_actions))

            
            if self.sound_action_timer > 0:
                self.actions[0][12] = 0  # Set the action to 0
                self.sound_action_timer -= 1  # Decrement the timer
            elif self.actions[0][12] != 0:  # If a non-zero action is taken
                self.sound_action_timer = 15  # Start the timer - set to 15 steps / ~15s at current code performance

            print("sound action timer", self.sound_action_timer)
            

            #Modify so that it only sends a new sound command at most every 10s
            #IF last action index not equal 0, then action index equals zero 

        return self.actions, agent_states

Experience = namedtuple('Experience', ['state', 'action', 'reward','done'])

class ExperienceSource:
    """
    Simple n-step experience source using single or multiple environments

    Every experience contains n list of Experience entries
    """
    def __init__(self, env, agent, steps_count=2, steps_delta=1, vectorized=False):
        """
        Create simple experience source
        :param env: environment or list of environments to be used
        :param agent: callable to convert batch of states into actions to take
        :param steps_count: count of steps to track for every experience chain
        :param steps_delta: how many steps to do between experience items
        :param vectorized: support of vectorized envs from OpenAI universe

        Copyright 2017- Maxim Lapan <max.lapan@gmail.com>

        Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in t
        """
        assert isinstance(env, (gymnasium.Env, list, tuple))
        assert isinstance(agent, BaseAgent)
        assert isinstance(steps_count, int)
        assert steps_count >= 1
        assert isinstance(vectorized, bool)
        if isinstance(env, (list, tuple)):
            self.pool = env
        else:
            self.pool = [env]
        self.agent = agent
        self.steps_count = steps_count
        self.steps_delta = steps_delta
        self.total_rewards = []
        self.total_steps = []
        self.vectorized = vectorized

    def __iter__(self):
        states, agent_states, histories, cur_rewards, cur_steps = [], [], [], [], []
        env_lens = []
        for env in self.pool:
            obs = env.reset()
            # if the environment is vectorized, all it's output is lists of results.
            # Details are here: https://github.com/openai/universe/blob/master/doc/env_semantics.rst
            if self.vectorized:
                obs_len = len(obs)
                states.extend(obs)
            else:
                obs_len = 1
                states.append(obs)
            env_lens.append(obs_len)

            for _ in range(obs_len):
                histories.append(deque(maxlen=self.steps_count))
                cur_rewards.append(0.0)
                cur_steps.append(0)
                agent_states.append(self.agent.initial_state())

        iter_idx = 0
        while True:
            actions = [None] * len(states)
            states_input = []
            states_indices = []
            for idx, state in enumerate(states):
                if state is None:
                    actions[idx] = self.pool[0].action_space.sample()  # assume that all envs are from the same family
                else:
                    states_input.append(state)
                    states_indices.append(idx)
            if states_input:
                states_actions, new_agent_states = self.agent(states_input, agent_states)
                for idx, action in enumerate(states_actions):
                    g_idx = states_indices[idx]
                    actions[g_idx] = action
                    agent_states[g_idx] = new_agent_states[idx]
            grouped_actions = _group_list(actions, env_lens)

            global_ofs = 0
            for env_idx, (env, action_n) in enumerate(zip(self.pool, grouped_actions)):
                if self.vectorized:
                    next_state_n, r_n, is_done_n, _ = env.step(action_n)
                else:
                    next_state, r, is_done, _ = env.step(action_n[0])
                    next_state_n, r_n, is_done_n = [next_state], [r], [is_done]

                for ofs, (action, next_state, r, is_done) in enumerate(zip(action_n, next_state_n, r_n, is_done_n)):
                    idx = global_ofs + ofs
                    state = states[idx]
                    history = histories[idx]

                    cur_rewards[idx] += r
                    cur_steps[idx] += 1
                    if state is not None:
                        history.append(Experience(state=state, action=action, reward=r, done=is_done))
                    if len(history) == self.steps_count and iter_idx % self.steps_delta == 0:
                        yield tuple(history)
                    states[idx] = next_state
                    if is_done:
                        # in case of very short episode (shorter than our steps count), send gathered history
                        if 0 < len(history) < self.steps_count:
                            yield tuple(history)
                        # generate tail of history
                        while len(history) > 1:
                            history.popleft()
                            yield tuple(history)
                        self.total_rewards.append(cur_rewards[idx])
                        self.total_steps.append(cur_steps[idx])
                        cur_rewards[idx] = 0.0
                        cur_steps[idx] = 0
                        # vectorized envs are reset automatically
                        states[idx] = env.reset() if not self.vectorized else None
                        agent_states[idx] = self.agent.initial_state()
                        history.clear()
                global_ofs += len(action_n)
            iter_idx += 1

    def pop_total_rewards(self):
        r = self.total_rewards
        if r:
            self.total_rewards = []
            self.total_steps = []
        return r

    def pop_rewards_steps(self):
        res = list(zip(self.total_rewards, self.total_steps))
        if res:
            self.total_rewards, self.total_steps = [], []
        return res

def _group_list(items, lens):
    """
    Unflat the list of items by lens
    :param items: list of items
    :param lens: list of integers
    :return: list of list of items grouped by lengths
    """
    res = []
    cur_ofs = 0
    for g_len in lens:
        res.append(items[cur_ofs:cur_ofs+g_len])
        cur_ofs += g_len
    return res


# those entries are emitted from ExperienceSourceFirstLast. Reward is discounted over the trajectory piece
ExperienceFirstLast = collections.namedtuple('ExperienceFirstLast', ('state', 'action', 'reward', 'last_state'))


class ExperienceSourceFirstLast(ExperienceSource):
    """
    This is a wrapper around ExperienceSource to prevent storing full trajectory in replay buffer when we need
    only first and last states. For every trajectory piece it calculates discounted reward and emits only first
    and last states and action taken in the first state.

    If we have partial trajectory at the end of episode, last_state will be None
    """
    def __init__(self, env, agent, gamma, steps_count=1, steps_delta=1, vectorized=False):
        assert isinstance(gamma, float)
        super(ExperienceSourceFirstLast, self).__init__(env, agent, steps_count+1, steps_delta, vectorized=vectorized)
        self.gamma = gamma
        self.steps = steps_count

    def __iter__(self):
        for exp in super(ExperienceSourceFirstLast, self).__iter__():
            if exp[-1].done and len(exp) <= self.steps:
                last_state = None
                elems = exp
            else:
                last_state = exp[-1].state
                elems = exp[:-1]
            total_reward = 0.0
            for e in reversed(elems):
                total_reward *= self.gamma
                total_reward += e.reward
            yield ExperienceFirstLast(state=exp[0].state, action=exp[0].action,
                                      reward=total_reward, last_state=last_state)

class ExperienceReplayBuffer:
    def __init__(self, experience_source, buffer_size):
        assert isinstance(experience_source, (ExperienceSource, type(None)))
        assert isinstance(buffer_size, int)
        self.experience_source_iter = None if experience_source is None else iter(experience_source)
        self.buffer = []
        self.capacity = buffer_size
        self.pos = 0

    def __len__(self):
        return len(self.buffer)

    def __iter__(self):
        return iter(self.buffer)

    def sample(self, batch_size):
        """
        Get one random batch from experience replay
        TODO: implement sampling order policy
        :param batch_size:
        :return:
        """
        if len(self.buffer) <= batch_size:
            return self.buffer
        # Warning: replace=False makes random.choice O(n)
        keys = np.random.choice(len(self.buffer), batch_size, replace=True)
        return [self.buffer[key] for key in keys]

    def _add(self, sample):
        if len(self.buffer) < self.capacity:
            self.buffer.append(sample)
        else:
            self.buffer[self.pos] = sample
        self.pos = (self.pos + 1) % self.capacity

    def populate(self, samples):
        """
        Populates samples into the buffer
        :param samples: how many samples to populate
        """
        for _ in range(samples):
            entry = next(self.experience_source_iter)
            self._add(entry)

class PrioritizedReplayBuffer(ExperienceReplayBuffer):
    def __init__(self, experience_source, buffer_size, alpha):
        super(PrioritizedReplayBuffer, self).__init__(experience_source, buffer_size)
        assert alpha > 0
        self._alpha = alpha

        it_capacity = 1
        while it_capacity < buffer_size:
            it_capacity *= 2

        self._it_sum = utils.SumSegmentTree(it_capacity)
        self._it_min = utils.MinSegmentTree(it_capacity)
        self._max_priority = 1.0

    def _add(self, *args, **kwargs):
        idx = self.pos
        super()._add(*args, **kwargs)
        self._it_sum[idx] = self._max_priority ** self._alpha
        self._it_min[idx] = self._max_priority ** self._alpha

    def _sample_proportional(self, batch_size):
        res = []
        for _ in range(batch_size):
            mass = random.random() * self._it_sum.sum(0, len(self) - 1)
            idx = self._it_sum.find_prefixsum_idx(mass)
            res.append(idx)
        return res

    def sample(self, batch_size, beta):
        assert beta > 0

        idxes = self._sample_proportional(batch_size)

        weights = []
        p_min = self._it_min.min() / self._it_sum.sum()
        max_weight = (p_min * len(self)) ** (-beta)

        for idx in idxes:
            p_sample = self._it_sum[idx] / self._it_sum.sum()
            weight = (p_sample * len(self)) ** (-beta)
            weights.append(weight / max_weight)
        weights = np.array(weights, dtype=np.float32)
        samples = [self.buffer[idx] for idx in idxes]
        return samples, idxes, weights

    def update_priorities(self, idxes, priorities):
        assert len(idxes) == len(priorities)
        for idx, priority in zip(idxes, priorities):
            assert priority > 0
            assert 0 <= idx < len(self)
            self._it_sum[idx] = priority ** self._alpha
            self._it_min[idx] = priority ** self._alpha

            self._max_priority = max(self._max_priority, priority)

#This might require major modification 

def test_net(net, env, count=NUM_ENVS, device=device):
    rewards = 0.0
    steps = 0
    for _ in range(count):
        obs = env.reset()
        while True:
            obs_v = float32_preprocessor([obs]).to(device)
            mu_v = net(obs_v)
            action = mu_v.squeeze(dim=0).data.cpu().numpy()
            #actionA = np.clip(actionA, -1.7, 1.7)
            obs, reward, done, _ = env.step(action,obs)
            rewards += reward

            steps += 1
            if done:
                break
    return rewards / count

def unpack_batch_ddqn(batch, device=device):
    states, actions, rewards, dones, last_states, critic_states_a_v = [], [], [], [], [], []
    for exp in batch:
        states.append(exp.state)
        actions.append(exp.action)
        rewards.append(exp.reward)
        dones.append(exp.last_state is None)
        if exp.last_state is None:
            last_states.append(exp.state)
        else:
            last_states.append(exp.last_state)
    states_actions_tensor = torch.tensor(states[0][0], dtype=torch.float32).to(device)
    states_cam1_tensor = torch.tensor(states[0][1][0], dtype=torch.float32).to(device)
    states_cam2_tensor = torch.tensor(states[0][1][1], dtype=torch.float32).to(device)
    states_other_tensor = torch.tensor(states[0][1][2], dtype=torch.float32).to(device)
    states_v = [states_actions_tensor, states_cam1_tensor, states_cam2_tensor, states_other_tensor]
    actions = np.stack(actions)
    actions_v = torch.tensor(actions, dtype=torch.float32).to(device)
    rewards_v = torch.tensor(rewards, dtype=torch.float32).to(device)
    last_states_actions_tensor = torch.tensor(last_states[0][0], dtype=torch.float32).to(device)
    last_states_cam1_tensor = torch.tensor(last_states[0][1][0], dtype=torch.float32).to(device)
    last_states_cam2_tensor = torch.tensor(last_states[0][1][1], dtype=torch.float32).to(device)
    last_states_other_tensor = torch.tensor(last_states[0][1][2], dtype=torch.float32).to(device)
    last_states_v = [last_states_actions_tensor, last_states_cam1_tensor, last_states_cam2_tensor, last_states_other_tensor]
    dones_t = torch.BoolTensor(dones).to(device)
    critic_states_a_v = [states_cam1_tensor, states_cam2_tensor, states_other_tensor, actions_v]
    return states_v, actions_v, rewards_v, dones_t, last_states_v, critic_states_a_v

def distr_projection(next_distr_v, rewards_v, dones_mask_t,
                     gamma, device="cpu"):
    next_distr = next_distr_v.data.cpu().numpy()
    rewards = rewards_v.data.cpu().numpy()
    dones_mask = dones_mask_t.cpu().numpy().astype(bool)
    batch_size = len(rewards)
    proj_distr = np.zeros((batch_size, N_ATOMS), dtype=np.float32)

    for atom in range(N_ATOMS):
        tz_j = np.minimum(VMAX, np.maximum(
            VMIN, rewards + (VMIN + atom * DELTA_Z) * gamma))
        b_j = (tz_j - VMIN) / DELTA_Z
        l = np.floor(b_j).astype(np.int64)
        u = np.ceil(b_j).astype(np.int64)
        eq_mask = u == l
        proj_distr[eq_mask, l[eq_mask]] += \
            next_distr[eq_mask, atom]
        ne_mask = u != l
        proj_distr[ne_mask, l[ne_mask]] += \
            next_distr[ne_mask, atom] * (u - b_j)[ne_mask]
        proj_distr[ne_mask, u[ne_mask]] += \
            next_distr[ne_mask, atom] * (b_j - l)[ne_mask]

    if dones_mask.any():
        proj_distr[dones_mask] = 0.0
        tz_j = np.minimum(VMAX, np.maximum(
            VMIN, rewards[dones_mask]))
        b_j = (tz_j - VMIN) / DELTA_Z
        l = np.floor(b_j).astype(np.int64)
        u = np.ceil(b_j).astype(np.int64)
        eq_mask = u == l
        eq_dones = dones_mask.copy()
        eq_dones[dones_mask] = eq_mask
        if eq_dones.any():
            proj_distr[eq_dones, l[eq_mask]] = 1.0
        ne_mask = u != l
        ne_dones = dones_mask.copy()
        ne_dones[dones_mask] = ne_mask
        if ne_dones.any():
            proj_distr[ne_dones, l[ne_mask]] = (u - b_j)[ne_mask]
            proj_distr[ne_dones, u[ne_mask]] = (b_j - l)[ne_mask]
    return torch.FloatTensor(proj_distr).to(device)

def main():
    save_path = os.path.join("saves", "a2c-" + "JayNetv1.0")
    os.makedirs(save_path, exist_ok=True)

    env = JayEnv()

    test_env = JayEnv()
    writer = SummaryWriter(comment="JayNetv1.0")
    net_actor = JayActor(test_env.observation_space,test_env.action_space).to(device)
    net_critic = JayCritic(test_env.observation_space,test_env.action_space, N_ATOMS, VMIN, VMAX).to(device)
    tgt_net_actor = TargetNet(net_actor)
    tgt_net_critic = TargetNet(net_critic)
    agent = AgentD4PG(net_actor, device=device)
    exp_source = ExperienceSourceFirstLast(env, agent, gamma=GAMMA, steps_count=REWARD_STEPS)
    buffer = ExperienceReplayBuffer(exp_source, buffer_size=REPLAY_SIZE)

    optimizer_actor = optim.Adam(net_actor.parameters(), lr=LEARNING_RATE_ACTOR)
    optimizer_critic = optim.Adam(net_critic.parameters(), lr=LEARNING_RATE_CRITIC)

    frame_idx = 0
    best_reward = None

    with RewardTracker(writer, STOP_REWARD) as tracker:
        with TBMeanTracker(writer, batch_size=1) as tb_tracker:
            while True:
                frame_idx += 1
                #gonna want to implement some kind of saving the of the replay buffer, so that 
                #I can initialize a session with old data
                print("987 test")
                buffer.populate(1)
                rewards_steps = exp_source.pop_rewards_steps()

                if rewards_steps:
                    rewards, steps = zip(*rewards_steps)
                    tb_tracker.track("episode_steps", steps[0], frame_idx)
                    tracker.reward(rewards[0], frame_idx)

                if len(buffer) < REPLAY_INITIAL:
                    continue

                    
                batch = buffer.sample(BATCH_SIZE)
                states_v, actions_v, rewards_v, dones_mask, last_states_v, critic_states_a_v= unpack_batch_ddqn(batch, device) 
                print("1181 critic_states_a_v",critic_states_a_v.shape)

                # train Arthur critic
                optimizer_critic.zero_grad()
                crt_distr_v = net_critic(critic_states_a_v)[2]
                last_act_v = tgt_net_actor.target_model([last_states_v[1], last_states_v[2], last_states_v[3]])
                #last_distr_v = F.softmax(tgt_net_critic.target_model(critic_states_a_v), dim=1)
                last_distr_v = tgt_net_critic.target_model(critic_states_a_v)[1]
                proj_distr_v = distr_projection(last_distr_v, rewards_v, dones_mask, gamma=GAMMA**REWARD_STEPS, device=device)
                prob_dist_v = -F.log_softmax(crt_distr_v, dim=1) * proj_distr_v
                critic_loss_v = prob_dist_v.sum(dim=1).mean()
                critic_loss_v.backward()
                optimizer_critic.step()
                tb_tracker.track("loss_critic", critic_loss_v, frame_idx)

                # train Arthur actor
                optimizer_actor.zero_grad()
                cur_actions_v = net_actor([states_v[1], states_v[2], states_v[3]])
                crt_distr_v = net_critic(critic_states_a_v)[1]
                actor_loss_v = -net_critic.distr_to_q(crt_distr_v)
                actor_loss_v = actor_loss_v.mean()
                actor_loss_v.backward()
                optimizer_actor.step()
                tb_tracker.track("loss_actor", actor_loss_v,
                                 frame_idx)

                tgt_net_actor.alpha_sync(alpha=1 - 1e-3)
                tgt_net_critic.alpha_sync(alpha=1 - 1e-3)
                print("end")

if __name__ == "__main__":
    main()
