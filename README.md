# OTDR-Based Fiber Intrusion Detection System

## Overview

This project presents an Optical Fiber Bending Loss Application for Door Hinge Security Monitoring. The system utilizes optical fiber sensing, OTDR measurements, and Arduino-based processing to detect and analyze door movement caused by environmental and physical disturbances.

By wrapping a single-mode optical fiber around a door hinge, bend-induced optical attenuation is generated when the door moves. The system analyzes these optical losses to estimate door deflection, classify intrusion events, and monitor structural behavior in real time.

---

## Objectives

* Monitor door deflection using optical fiber bending loss.
* Detect intrusion events through optical attenuation analysis.
* Utilize OTDR measurements for fault localization and disturbance monitoring.
* Analyze the impact of regional wind conditions on door movement.
* Classify door interactions caused by humans and animals.
* Develop a low-cost smart monitoring solution for infrastructure security.

---

## System Components

### Hardware

* Single Mode Optical Fiber (SMF-28)
* Arduino Uno
* Optical Source
* Photodetector
* OTDR (Optical Time Domain Reflectometer)
* Door Hinge Test Structure

### Software

* Arduino IDE
* Embedded C/C++
* Serial Monitor Interface

---

## Working Principle

1. Optical fiber is wrapped around the door hinge.
2. Door movement changes the bend radius of the fiber.
3. Fiber bending causes optical power attenuation.
4. Optical loss is measured using OTDR and photodetection techniques.
5. Arduino processes the measured values.
6. The system estimates door angle and classifies the disturbance source.
7. Monitoring results are displayed through the serial interface.

---

## Features

* Real-time monitoring
* Fiber optic sensing
* OTDR-based fault localization
* Door angle estimation
* Entity classification
* Regional wind modeling
* Security monitoring
* Smart infrastructure applications

---

## Entity Classification

The system identifies possible sources of door movement based on force thresholds:

| Entity           | Force (N) |
| ---------------- | --------- |
| Cow              | 1000      |
| Goat             | 300       |
| Dog              | 215       |
| Angry Person     | 180       |
| Happy Person     | 75        |
| Cat              | 50        |
| Child/Sad Person | 30        |
| Elderly Person   | 20        |

---

## Regional Wind Modeling

The system accounts for regional wind conditions across India:

* Western Coastal Region
* Eastern Himalayan Foothills
* North Indian Plains
* Deccan Plateau

These wind forces are incorporated into total door loading calculations.

---

## Results

Key outcomes obtained during testing:

* Door deflection monitoring under varying force conditions.
* Bend-loss correlation with door angle.
* Intrusion event detection through optical attenuation.
* Entity classification accuracy ranging from 85% to 98%.
* Successful implementation of OTDR-assisted optical monitoring.

---

## Applications

* Smart Building Security
* Infrastructure Monitoring
* Structural Health Monitoring
* Intrusion Detection Systems
* Fiber Optic Sensor Networks

---

## Technologies Used

* Arduino Uno
* Embedded C
* Optical Fiber Communication
* OTDR
* Optical Sensors
* Signal Monitoring
* Structural Health Monitoring

---

## Future Improvements

* Machine Learning-based classification
* Temperature compensation
* Multi-door monitoring network
* Cloud-based IoT dashboard
* Advanced OTDR event analysis

---

## Author

Shivam Kumar

B.Tech, Electronics and Communication Engineering

Indian Institute of Technology (ISM) Dhanbad
