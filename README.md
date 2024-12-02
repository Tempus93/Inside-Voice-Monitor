# Inside-Voice-Monitor
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

| Component | Arduino Pin |
|-----------|-------------|
| RS | Digital Pin 7 |
| Enable | Digital Pin 6 |
| D4 | Digital Pin 5 |
| D5 | Digital Pin 4 |
| D6 | Digital Pin 3 |
| D7 | Digital Pin 2 |

### LED Pins
| Color  | Pins |
| ------------- | ------------- |
| Blue  | 13  |
| Green  | 8  |
| Red  | 12  |

### UltraSonic Sensor Pins
Trigger: Digital Pin 9

Echo: Digital Pin 10

### Microphone Pins
Input: Analog Pin 0


## System States

### Scanning State

- Continuously monitors distance
Displays current distance in centimeters and inches
Transitions to listening state when an object is detected for 3 seconds


### Listening State

- Measures sound levels
Displays decibel readings and sound intensity
Returns to scanning state if no object is detected for 10 seconds



## Dependencies
LiquidCrystal Library

Custom Distance.h Library

Custom Decibel.h Library

## Usage Instructions

1. Upload the code to your Arduino board
2. Connect all hardware components as specified
3. Power on the Arduino
4. The system will start in scanning mode
5. Approach the sensor to trigger the listening state
5. Observe real-time distance and sound level readings on the LCD

## Customization

- Modify sensor threshold times in the code
- Adjust pin configurations as needed
- Extend libraries for additional functionality

## Debugging

- Serial monitor provides additional state and reading information
Blue LED indicates state transitions

# Author
Justin Downer
 - UBID: 50429104
 - Email: jrdowner@buffalo.edu

CSE 321 Final Project - Team 29


## Potential Improvements

- Implement non-blocking timing

- Add more robust error handling

- Create more granular state transitions


