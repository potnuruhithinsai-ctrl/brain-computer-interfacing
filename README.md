## VIDYUT: Brain-Computer Interface (BCI) System

### Overview
[cite_start]Brain-computer interfaces help people send messages and execute commands using brain signals[cite: 8]. [cite_start]**VIDYUT** [cite: 14] [cite_start]is a low-cost, interactive BCI system that explores how EEG signals can be recorded and turned into actions on a computer[cite: 8, 19]. [cite_start]Specifically, this project acquires weak EEG signals generated during eye blinking, processes them efficiently, and uses them as an input command to make the dinosaur jump in the Chrome Dino game[cite: 16].

### Key Features
* [cite_start]**Real-Time Blink Detection:** An action on the computer gets triggered for every eye-blink[cite: 16].
* [cite_start]**Custom Signal Conditioning:** Utilizes custom-built analog signal conditioning circuits to filter and amplify weak biometric signals[cite: 11, 19].
* [cite_start]**Embedded Processing:** Implements a moving-average filtering algorithm for reliable peak detection directly on an ESP32 microcontroller[cite: 12, 13].
* [cite_start]**Muscle Movement Tracking:** Includes logic for interpreting wrist movement on either arm to move a computer cursor using envelope detection[cite: 13, 17].

---

### Hardware Architecture

The human brain produces extremely weak EEG signals, typically around 0.5 µV. To accurately read these signals, the hardware pipeline is broken down into three main stages:

* [cite_start]**Signal Acquisition:** Brain signals are collected using simple electrodes placed on different body parts[cite: 10].
* [cite_start]**Analog Signal Conditioning:** Signals are routed through band-pass filters to remove any noise[cite: 11].
* [cite_start]**Amplification:** Because the voltage generated from these signals is low, an amplifier is also added[cite: 12]. 
* [cite_start]**Microcontroller:** A microcontroller (ESP32) is used to convert analog signal to digital data[cite: 12].

---

### Software & Algorithms

The digital signal processing relies on identifying significant deviations from a baseline signal. The repository includes two approaches to peak detection written in C:

* **Threshold Detection (`peakdet1.c`):** Uses a static threshold combined with rising and falling edge logic. It requires at least three consecutive samples to verify if a signal is actively peaking above a defined `PEAK_THRESHOLD`.
* **Moving Average Deviation (`peakdet2.c`):** Uses a circular buffer to maintain a running average of the incoming signal. A peak is detected when the current sample deviates significantly (by a defined `DEVIATION_THRESHOLD`) from the local moving average. This method dynamically smooths fluctuations and random noise, making it highly effective for real-time blink detection.

---

### Methodology & Workflow

1. [cite_start]**Capture:** It starts with collecting brain signals using simple electrodes[cite: 10].
2. [cite_start]**Filter & Amplify:** The analog front-end isolates the blink components and the amplifier boosts them[cite: 11, 12].
3. [cite_start]**Digitize:** The ESP32's ADC converts the analog signal to digital data[cite: 12].
4. [cite_start]**Process:** The embedded C code performs moving-average filtering and peak detection for blinking[cite: 13].
5. [cite_start]**Execute:** An action on the computer gets triggered for every eye-blink[cite: 16].

---

### Team

[cite_start]This project was developed for the ACM Project Expo[cite: 1, 3].

* [cite_start]**Project Mentors:** Charan, Dhanya [cite: 5]
* [cite_start]**Project Mentees:** Hithinsai, Aryan, Hadi, Chithropal S [cite: 6]
