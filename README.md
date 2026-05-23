# Brain Computer Interface (BCI)

## Introduction
Brain Computer Interface (BCI) is a technology that enables communication between the human brain and external electronic systems using brain-generated electrical signals. These signals are commonly known as EEG (Electroencephalogram) signals. Our project focuses on building a simple and interactive BCI system capable of detecting eye blinks and converting them into real-time computer actions.

---

# Abstract
This project demonstrates the design and implementation of a low-cost Brain Computer Interface system using analog electronics and embedded systems. The system acquires weak EEG signals generated during eye blinking, processes them through filtering and amplification stages, and converts them into useful digital commands using an ESP32 microcontroller.

The acquired EEG signals are first conditioned using analog filters to remove noise and unwanted interference. An AD620 instrumentation amplifier is used to amplify the extremely weak signals to a measurable range. The amplified signals are then processed inside the ESP32 using moving average and peak detection algorithms for reliable eye-blink detection.

Finally, the detected eye blinks are used to control the Chrome Dino game, where every blink triggers the dinosaur to jump. The project combines biomedical instrumentation, signal processing, embedded programming, and human-computer interaction into an innovative and practical application.

---

# Objectives
- To acquire EEG signals generated during eye blinking
- To design analog circuits for signal conditioning
- To remove noise using second-order filtering
- To amplify weak EEG signals using AD620
- To process signals digitally using ESP32
- To implement moving average and peak detection algorithms
- To create a real-time human-computer interaction system

---

# Methodology

## 1. Signal Acquisition
EEG signals associated with eye blinking are collected using electrodes placed on the body. These signals are extremely weak and highly sensitive to noise.

## 2. Analog Signal Conditioning
The acquired signals pass through a second-order filter circuit to remove high-frequency noise and interference. Proper filtering improves signal quality and isolates useful EEG components.

## 3. Signal Amplification
An AD620 instrumentation amplifier is used to amplify the filtered EEG signals.

### Features of AD620
- High accuracy
- Low noise
- High common-mode rejection ratio
- Suitable for biomedical signal amplification

## 4. Digital Signal Processing
The amplified signal is fed into the ESP32 microcontroller.

Inside the ESP32:
- Moving average filtering smooths the signal
- Peak detection identifies eye blinks
- Noise fluctuations are reduced

## 5. Real-Time Application
Whenever an eye blink peak is detected, the ESP32 sends an output command to the Chrome Dino game, causing the dinosaur to jump automatically.

---

# Components Used
- Electrodes
- AD620 Instrumentation Amplifier
- ESP32 Microcontroller
- Second-Order Filter Circuit
- Resistors and Capacitors
- Connecting Wires and Breadboard
- Computer System

---

# Working Principle
1. Eye blink produces EEG activity
2. Electrodes capture the EEG signal
3. Filter circuit removes unwanted noise
4. AD620 amplifies the weak signal
5. ESP32 processes the signal digitally
6. Peak detection identifies eye blinks
7. Blink triggers dinosaur jump in Chrome Dino game

---

# Results and Findings
- Successful detection of eye blinks using EEG signals
- Noise reduction achieved through filtering
- Reliable signal amplification using AD620
- Real-time blink detection using ESP32
- Smooth interaction with Chrome Dino game
- Demonstrated practical implementation of a low-cost BCI system

---

# Applications
- Assistive technology for disabled individuals
- Human-computer interaction systems
- Gaming control systems
- Biomedical signal monitoring
- Smart control applications

---

# Future Scope
- Wireless EEG signal acquisition
- Improved signal accuracy using advanced filters
- Machine learning-based signal classification
- Control of multiple applications using brain signals
- Real-time wheelchair or robotic control

---

# Conclusion
This project successfully demonstrates a simple Brain Computer Interface system using analog signal conditioning and embedded processing techniques. By combining EEG signal acquisition, filtering, amplification, and digital signal processing, the system converts human eye blinks into real-time computer actions. The project highlights the potential of low-cost BCI technology in interactive and biomedical applications.
