#ifndef DISTANCE_CALC_H
#define DISTANCE_CALC_H
#include <Arduino.h>

class Distance {
public:
  Distance(int i = 0);

  // setup the Pins for the sensor
  void setupUSSensor();

  // send out UltraSonic Pulses
  void Pulse();

  // get the distance recorded from pulses
  long PulsetoCentimeters();

  // timer for state switch when person in range
  bool inrange(int duration);
  
  // timer for state switch when person is NOT in range
  bool Ninrange(int duration);

private:
  //to initalize the class in main file
  int thro;

  //helper for inrange timer
  unsigned long inrangestart;

  //helper for NOT in range timer
  unsigned long Ninrangestart;

};

#endif