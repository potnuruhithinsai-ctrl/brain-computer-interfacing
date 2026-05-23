## VIDYUT: Brain-Computer Interface (BCI) System

### Overview
Brain-computer interfaces help people send messages and execute commands using brain signals. 

It is a low-cost, interactive BCI system that explores how EEG signals can be recorded and turned into actions on a computer. 

Specifically, this project acquires weak EEG signals generated during eye blinking, processes them efficiently, and uses them as an input command to make the dinosaur jump in the Chrome Dino game.

### Key Features
* **Real-Time Blink Detection:** An action on the computer gets triggered for every eye-blink.
* **Custom Signal Conditioning:** Utilizes custom-built analog signal conditioning circuits to filter and amplify weak biometric signals
* **Embedded Processing:** Implements a moving-average filtering algorithm for reliable peak detection directly on an ESP32 microcontroller.
* **Muscle Movement Tracking:** Includes logic for interpreting wrist movement on either arm to move a computer cursor using envelope detection.

---

### Hardware Architecture

The human brain produces extremely weak EEG signals, typically around 0.5 µV. To accurately read these signals, the hardware pipeline is broken down into three main stages:

* **Signal Acquisition:** Brain signals are collected using simple electrodes placed on different body parts.
* **Analog Signal Conditioning:** Signals are routed through band-pass filters to remove any noise.
* **Amplification:** Because the voltage generated from these signals is low, an amplifier is also added. 
* **Microcontroller:** A microcontroller (ESP32) is used to convert analog signal to digital data.

---

### Software & Algorithms

The digital signal processing relies on identifying significant deviations from a baseline signal. The repository includes two approaches to peak detection written in C:

* **Threshold Detection (`peakdet1.c`):** Uses a static threshold combined with rising and falling edge logic. It requires at least three consecutive samples to verify if a signal is actively peaking above a defined `PEAK_THRESHOLD`.
* **Moving Average Deviation (`peakdet2.c`):** Uses a circular buffer to maintain a running average of the incoming signal. A peak is detected when the current sample deviates significantly (by a defined `DEVIATION_THRESHOLD`) from the local moving average. This method dynamically smooths fluctuations and random noise, making it highly effective for real-time blink detection.

---

### Methodology & Workflow

1. **Capture:** It starts with collecting brain signals using simple electrodes.
2. **Filter & Amplify:** The analog front-end isolates the blink components and the amplifier boosts them.
3. **Digitize:** The ESP32's ADC converts the analog signal to digital data.
4. **Process:** The embedded C code performs moving-average filtering and peak detection for blinking.
5. **Execute:** An action on the computer gets triggered for every eye-blink.

---

### Team

This project was developed as a part ACM NITK club work. 

* **Project Mentors:** Charan, Dhanya 
* **Project Mentees:** Hithinsai, Aryan, Hadi, Chithropal S 
