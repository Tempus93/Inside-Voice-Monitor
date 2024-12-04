#ifndef DECIBEL_METER_H
#define DECIBEL_METER_H

#include <Arduino.h>

class DecibelMeter {
public:
    // calibration factor in case i need to tweak the potentometer on microphone
    DecibelMeter(float calibrationFactor = 1.0);

    // Measure current sound level in decibels (as integer)
    int measureDecibels();

    // setup the inital pins and such
    void setup(int in = A0, int rled = 12, int gled = 8, int bled = 13);

    char loudness_Char();


private:
    // Analog pin for sound sensor
    int _pin;

    // Calibration factor to adjust sensitivity
    float _calibrationFactor;

    // Convert analog reading to voltage
    float getVoltage(int rawValue);

    // Calculate sound pressure level (decibels)
    float calculateSPL(float voltage);

    void loudness_LED(int Dbm);
};

#endif // DECIBEL_METER_H