#include "Distance.h"
//Two things I want the distance file to be done with
 int EchoPin;
 int TrigPin;

//Setups the UltraSonic Sensor's Pins
Distance::Distance(int in)
  : thro(in),
    inrangestart(0){}

//setup pins
void Distance::setupUSSensor(int Echo, int Trig){
  EchoPin = Echo; 
  TrigPin = Trig;

  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);

}

//Allows the sensor to send out a pulse in a 2 ms interval.
void Distance::Pulse(){
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
}

// Reads the time of receiving the pulse then converts it into CMs.
long Distance::PulsetoCentimeters(){
  long distance = pulseIn(EchoPin, HIGH, 1000000);
  return distance / 29 / 2;
}

bool Distance::inrange(long distance, int duration){
  long d = distance;

  // when person is in this distance range
  if(d > 0 && d <= 40){

     if (inrangestart == 0) {
          //if its still 0 while in range, get current millis since machine start
          inrangestart = millis();
          Serial.println("Obj detected at(MS): ");
          Serial.println(d);
        }

        
        // Check if we've been in range long enough (3s) )
        if (millis() - inrangestart >= duration) {
            // Reset timer for next check
            inrangestart = 0;
            return true;
        }

    }
    else{ 
      inrangestart = 0;
    }

    return false;
    
  }
  

bool Distance::Ninrange(long distance, int duration){
  long d = distance;
  
  // when person is in this distance range
  if(d > 40){

     if (Ninrangestart == 0) {
          //if its still 0 while in range, get current millis since machine start
          Ninrangestart = millis();
        }
        
        // Check if we've been in range long enough (3s) )
        if (millis() - Ninrangestart >= duration) {
            // Reset timer for next check
            Ninrangestart = 0;
            return true;
        }
     
  }  

  else {
        // Reset timer if out of range
        Ninrangestart = 0;
    }

    return false;
}