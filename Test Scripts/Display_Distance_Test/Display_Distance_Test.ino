#include <LiquidCrystal.h> // LCD Library from Arduino 

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //Pins for LCD Display

const int echopin = 9, trigpin = 10, RLED = 12, GLED = 8, BLED = 13; //Pins for both the UltraSonic Sensor & LEDs


LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //LCD Display Function 

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);  
  lcd.setCursor(10,0);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);

}

void loop() {
  long distance, cm;
  //Sensor sents out a ultrasonic pulse at a 2 ms interval
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpin, LOW);
  // Get the distance that is calculated in Centimeters
  distance = pulseIn(echopin, HIGH); // the pulse 
  cm = microsecondsToCentimeters(distance); /// gets the interval of recorded return pulses from the echo pin turned into Centimeters
  lcd.home();
  lcd.print("Distance:");

  lcd.setCursor(9,0);
  lcd.print(cm);
  delay(500);
  lcd.clear();


  
  if(cm >= 50){ //LEDs test with varying range
    digitalWrite(RLED, LOW);
    digitalWrite(BLED, LOW);
    digitalWrite(GLED, HIGH);
  }

  else if(cm >= 30){
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }

  else{
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
    digitalWrite(RLED, HIGH);
  }
  
}


long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}

