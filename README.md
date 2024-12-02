# Inside-Voice-Monitor
**Team 29** Justin Downer - jrdowner@buffalo.edu
## Project Overview
This Arduino project is a real-time environmental monitoring system that tracks distance and sound levels using an ultrasonic sensor and a decibel meter. The system switches between two primary states: scanning and listening, providing real-time feedback through an LCD display and LED indicators.
Features

### Distance Monitoring
Tracks object proximity using an ultrasonic sensor
### Sound Level Detection
Measures ambient noise levels in decibels
### State-Based System
Switches between scanning and listening states
### LCD Display 
Shows real-time sensor readings and system status
### Visual Indicators
Blue LED signals state changes, Red and Green LEDs signal noise level

## Hardware Requirements
Arduino Uno R3
Ultrasonic Sensor
Microphone Module (KY-508)
16x2 LCD Display
LEDs(Blue Red and Green)
Necessary jumper wires and breadboard

## Arduino Pin Configuration

### LCD Display Pins
RS: Digital Pin 7,
Enable: Digital Pin 6,
D4: Digital Pin 5,
D5: Digital Pin 4,
D6: Digital Pin 3,
D7: Digital Pin 2

### LED Pins
Blue LED: Digital Pin 13,
Red LED: Digital Pin 12,
Green LED: Digital Pin 8,

### UltraSonic Sensor Pins
Trigger: Digital Pin 9,
Echo: Digital Pin 10


### Microphone Pins
Input: Analog Pin 0





