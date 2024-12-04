#include <LiquidCrystal.h>
#include "Distance.h"
#include "Decibel.h"

// Team 29 - Justin Downer 50429104

//initalise the Distance and DecibelMeter Class Objects
Distance Sensor(0);
DecibelMeter DBs(1.0);

//buffer for sprintf implementation (16x02 LCD Display).
char buffer[16];

//buffer for Error Handing Msg regarding state switches
char Ebuffer[1024];

//Pins for LCD Display
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Blue LED pin 
const int BLED = 13; //pinMode is setup within the Dbs Object

// States for Arduino to swap into
enum States{
  scanning,
  listening
};


States currentState; //initial state is scanning

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Sensor.setupUSSensor();
  DBs.setup();
  currentState = scanning;
}

void loop() {
  //Sensor sents out a pulse at a 2 ms interval
  Sensor.Pulse();

  // Get the distance that is calculated in Centimeters
  long distance = Sensor.PulsetoCentimeters();


  switch(currentState){
    case listening:

      Serial.println("S: Listening\n");
      
      lcd.clear();
      sprintf(buffer,"How Loud?");
      lcd.print(buffer);

      lcd.setCursor(0, 1);
      sprintf(buffer,"%d DBm",DBs.measureDecibels());
      DBs.loudness_Char();
      lcd.print(buffer);

      delay(500);


      // if user steps out of range, times out the Listening state and reverts to scanning
      if(Sensor.Ninrange(distance ,5000)){ // 10s Timed-Out Timer
        currentState = scanning;
        lcd.clear();
        lcd.print("switching state...");
        Serial.println("switching state...\n");

        //indicate State Switching
        IndicateStateChange();
      }

    break;


    case scanning:
      // State notification on Serial
      Serial.println("State: Scanning\n");
    

      lcd.clear();
      // inital readings on Serial & LCD display
      sprintf(buffer, "Distance");
      lcd.print(buffer);
      lcd.setCursor(0,1);

      // Read Range in Both Centimeters & Inches
      sprintf(buffer,"%i Cm",distance);
      lcd.print(buffer);


      // once person is in range for at least 3 seconds
      if (Sensor.inrange(distance, 3000)){
        lcd.clear();
        lcd.print("switching state");
        //solid blue to indicate State Switching
        IndicateStateChange();
        currentState = listening;
        lcd.clear();
      }
    break;

    default: // incase the state fails to change into one of the two others
      lcd.clear();
      sprintf(Ebuffer,"Error State:%s",currentState);
      lcd.println("Back to Scanning");
      Serial.println(Ebuffer);

      //Long enough to see the error.
      currentState = scanning;

    break;
    
  }  
}

void IndicateStateChange(){
  digitalWrite(BLED, HIGH);
  delay(500);
  digitalWrite(BLED, LOW);
  delay(250);
  digitalWrite(BLED, HIGH);
  delay(250);
  digitalWrite(BLED, LOW);
}

