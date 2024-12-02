
//basic Microphone testing, Will switch to AnalogPin for DBm reading
#include <LiquidCrystal.h> // LCD Library from Arduino 


const int ledPin = 12; // Red LED
const int sensorPin = 11;//


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);// lights LED On/off
  pinMode(sensorPin, INPUT); //input of any sound recorded
  Serial.begin (9600);

}

void loop() {
  int sound = digitalRead(sensorPin);

  if(sound){
    digitalWrite(ledPin,HIGH);
    delay(500);
  }
  else{
        digitalWrite(ledPin,LOW);
  }
 
 
}
