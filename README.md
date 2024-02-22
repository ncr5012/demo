# Nick Rackley's Demo Repository

Welcome to the demo repository showcasing the software and hardware development skills of Nick Rackley. This repository contains selected projects that demonstrate my capabilities in developing sophisticated systems integrating both software and hardware components.

## Featured Projects

### 1. Reinforcement Learning Robot

**Project Overview:**
- An autonomously learning robot powered by a deep reinforcement learning agent.
- Continuously learns from passive human and environmental feedback, adapting its behavior to maximize positive human emotions and navigate its surroundings effectively.
- Designed and assembled all software and hardware components for this project.

**Skills Demonstrated:**
- **Software:** Python, C++, Deep Reinforcement Learning from Human Feedback (RLHF) in physical environments, Cloud Robotics, ROS2, Computer Vision for facial/emotional detection, Sensor Fusion, Sensor Firmware.
- **Hardware:** Circuit and power system design and assembly, LiPo battery integration, 3D chassis design and printing (Autodesk Fusion and 3D Printing), custom Mecanum wheel design and 3D printing, Brushless DC Motor and motor controller integration, integration of camera, ultrasonic distance sensor, speaker, and microphone.

**Video Demonstration:** [Watch here](https://youtu.be/BLXDSJCqv4M) - Demonstrates the robot operating in local mode, starting from scratch and learning about the world, akin to a newborn baby. At approximately 17:45, it begins to show emergent levels of intelligence and curiosity.

**Note:** Core IP files, including the core deep reinforcement learning loop and modified FogROS2 cloud deployment software, are omitted for proprietary reasons. Demos are available upon request. This project primarily showcases my proficiency in C++ and Python. Lapan, M. (2020). Deep Reinforcement Learning Hands-On: Apply modern RL methods to practical problems of chatbots, robotics, discrete optimization, web automation, and more (2nd ed.). Packt Publishing. Accelerated by ChatGPT.

### 2. Financial Transformer

**Project Overview:**
- An innovative project aiming to predict the prices of over 70 stocks for the next day using an autoregressive transformer model, not unlike language models (LLMs).

**Skills Demonstrated:**
- **Software:** Python, design and training of transformer architecture from scratch, optimization of training loops for RAM and compute constraints.
- **Data Science:** Python, data structure creation, API utilization for data collection, data partitioning and cleaning, optimization of data structures and algorithms for RAM constraints.

**Note:** The code shown will always be an obsolete version of the model with errors I have subsequently fixed, just in case I eventually train a model that effectively predicts stock market data. This is meant to show how I formed a structured approach towards a potentially impossible problem. The fact im applying for a job should tell you it hasn't been successful yet ; ). Accelerated by ChatGPT.

### 3. RAG LLM

**Project Overview:**
- A class project involving a Retrieve and Generate (RAG) Language Model (LLM) system.
- Processes a PDF by chunking it, embedding the chunks, and using the embeddings to recommend relevant content for arbitrary queries through the OpenAI API, enhancing query responses beyond the base GPT 3.5 model capabilities.

### 4. Multi-Agent Reinforcement Learning (MARL) Auction Game

**Project Overview:**
- A MARL implementation of an auction game from my MBA's Corporate Strategy class where three players bid on selling a quantity of a commodity (Shrimp), where the end price for all is decided by the collective quantity. 
- This was the project I used to teach myself to code, and also learn about reinforcement learning in depth.
- In hindsight, it probably wasnt the easiest project to learn to code on. It worked out, because I had the insight that if I chose a game that had a known Nash Equilibrium, and I trained agents to converge on the equilibrium, then I would definitively know I not only taught myself to code, but also that the reinforcement learning loop was really working.
- The game has a Nash Equilibrium of selling a quantity of 30, meaning that you are competitive against other players, the mathematically optimal answer is to always sell 30 shrimp.
- For a long time, the agents kept converging to sell quantities of 45. I could not figure out what my bug was. After extensive debugging, I figured out it wasnt a bug, it was emergent behavior...
- I had allowed the agents to see each others bids. The agents were quickly learning to encode some form of collusion with each other and signaling what their future bids would be.
- When I referenced materials from my class, they said 45 was the monopoly profits, if everybody were to collude together.
- Once I masked the agents actions from each other, they converged to 30. 

**Skills Demonstrated:**
- **Software:** Python, MARL
- **Life:** Taking a seemingly impossible problem I had absolutely no requisite skills to solve and structuring it in a way to be successful.

**Note:** This project heavily referenced Lapan, M. (2020). Deep Reinforcement Learning Hands-On: Apply modern RL methods to practical problems of chatbots, robotics, discrete optimization, web automation, and more (2nd ed.). Packt Publishing. NOT aided by ChatGPT! 


## Demo Videos

1. [Reinforcement Learning Robot Demo](https://youtu.be/BLXDSJCqv4M) - Demonstrates the robot learning from scratch in a local environment. It highlights the robot's journey to achieving a level of intelligence and curiosity.

2. [Sound Alarm on Motion Detection System](https://youtu.be/s_h7Naehl7I) - Showcases the integration of physical sensors with mobile apps through a home security system project, highlighting skills in mobile app development, cloud integration, and physical sensor integration.

