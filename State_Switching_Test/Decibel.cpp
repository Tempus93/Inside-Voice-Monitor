#include "Decibel.h"

const float NOISE_FLOOR = 20.0;   // Minimum threshold to filter out background noise
const int SAMPLE_WINDOW = 50;     // Number of samples to collect & pin
int RLED, GLED, BLED, SensorPin;


DecibelMeter::DecibelMeter(float calibrationFactor) 
    : _pin(SensorPin), _calibrationFactor(calibrationFactor) {}

float DecibelMeter::getVoltage(int rawValue) {
    return rawValue * (5.0 / 1023.0);
}

//pins setup
void DecibelMeter::setup(int microphone_pin, int r_led, int g_led , int b_led){
  SensorPin = microphone_pin;
  RLED = r_led; 
  GLED = g_led;
  BLED = b_led;

  pinMode(SensorPin, INPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  
}


float DecibelMeter::calculateSPL(float voltage) {
    // Conversion formula 
    float decibels = 20 * log10(voltage) + 70;
    return max(decibels, NOISE_FLOOR);
}

int DecibelMeter::measureDecibels() {
    unsigned long startMillis = millis();
    float peakToPeak = 0;
    unsigned int signalMax = 0;
    unsigned int signalMin = 1023;

    // Collect samples over a short window
    while (millis() - startMillis < SAMPLE_WINDOW) {
        int sample = analogRead(_pin);
        
        // Track peak-to-peak voltage
        if (sample < 1024) {
            if (sample > signalMax) {
                signalMax = sample;
            }
            else if (sample < signalMin) {
                signalMin = sample;
            }
        }
    }

    // Calculate peak-to-peak voltage
    peakToPeak = (signalMax - signalMin) * (5.0 / 1023.0);
    
    // Convert to decibels with calibration and round to nearest integer
    int decibels = round(calculateSPL(peakToPeak) * _calibrationFactor);
    
    return decibels;
}

void DecibelMeter::loudness_LED(int db){
   
    if(db <= 52){
      //Green led blinks(low volume, bring it up)
      digitalWrite(RLED, 0);

      digitalWrite(GLED, 0);
      delay(300);
      digitalWrite(GLED, 1);
      delay(300);
      digitalWrite(GLED, 0);   
    }

    if(db > 52 && db <= 57){
      // perfect volume, NO NOTES :D
      digitalWrite(RLED, 0);
      digitalWrite(GLED,1);
    }

    if(db > 57 && db <= 63){
      
      digitalWrite(GLED,0);
      digitalWrite(RLED,0);
      delay(150);
      digitalWrite(RLED,1);
      delay(150);
      digitalWrite(RLED,0);

      digitalWrite(RLED,1);
    }

    if(db > 63){
      // NOOO TOOO LOUDD
      digitalWrite(GLED, 0);
      digitalWrite(RLED,1);


    }

}

char DecibelMeter::loudness_Char(){
  int db = measureDecibels();

  loudness_LED(db);
  if(db <= 52){return "Quiet";}

  if(db > 52 && db <= 57){ return "Perfect";}

  if(db > 58 && db <= 63){return "getting loud";}

  if(db > 63){return "TOO LOUD";}

  return "ofr";
}
