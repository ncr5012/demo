import cv2
from deepface import DeepFace
from collections import deque
import time
import numpy as np

# Open the webcam
cap = cv2.VideoCapture(0)

# Create a deque to store the last 1 second of emotion data
emotion_deque = deque(maxlen=30) # assuming 30 frames per second

while True:
    # Read a frame from the webcam
    ret, frame = cap.read()

    if not ret:
        break

    # Convert to RGB for DeepFace
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Detect emotions in the frame
    results = DeepFace.analyze(rgb_frame, actions = ['emotion'], enforce_detection = False)

    if isinstance(results, list):
        for result in results:
            x, y, w, h = result['region']['x'], result['region']['y'], result['region']['w'], result['region']['h']
            if x == 0 and y == 0:
                print("No face detected")
            else:
                cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)  # Draw a rectangle around the face

                # Append current timestamp and emotion data to deque
                emotion_deque.append((time.time(), result['emotion']))

                # Compute the average of each emotion over the last 1 second
                one_second_ago = time.time() - 1
                recent_emotions = [emotions for timestamp, emotions in emotion_deque if timestamp >= one_second_ago]
                if recent_emotions:
                    average_emotions = {emotion: round(np.mean([emo[emotion] for emo in recent_emotions])) for emotion in recent_emotions[0]}
                    print(average_emotions)
    else:
        print("No face detected")

    # Show the frame with any detected faces highlighted
    cv2.imshow('Video Feed', frame)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Clean up when done
cap.release()
cv2.destroyAllWindows()





