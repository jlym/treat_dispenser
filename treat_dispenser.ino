/*
  Based on 

  Stepper Motor Demonstration 3
  Stepper-Demo3.ino
  Demonstrates NEMA 17 Bipolar Stepper with L298N Driver
  DroneBot Workshop 2018 
  https://dronebotworkshop.com
*/

// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int STEPS_PER_REV = 200;

const int RADIO_RECIEVER = 3;

// Maximum amount of time between dispensing treats. (5 minutes.)
const unsigned long MAX_WAIT_MS = 300000;

// Time in ms between start-up and when a treat was last dispensed.
unsigned long lastDispenseMs = 0;

Stepper stepper_NEMA17(STEPS_PER_REV, 6, 7, 8, 9);

void setup() {
  //Serial.begin(9600);

  pinMode(RADIO_RECIEVER, INPUT);
  stepper_NEMA17.setSpeed(5);
}

void loop() {
  unsigned long now = millis();
  unsigned long diff = now - lastDispenseMs;
  bool maxTimePassed = diff >= MAX_WAIT_MS;
  
  /*
  String s;  
  Serial.println(s + "maxTimePassed: " + maxTimePassed );
  Serial.println(s + "now: " + now);
  Serial.println(s + "lastDispenseMs: " + lastDispenseMs);
  Serial.println(s + "diff: " + diff);
  Serial.println(s + "MAX_WAIT_MS: " + MAX_WAIT_MS);
  */

  // read the sensor value:
  bool isButtonPressed = digitalRead(RADIO_RECIEVER) == HIGH;

  if (maxTimePassed || isButtonPressed) {
    stepper_NEMA17.step(STEPS_PER_REV / 16);

    digitalWrite(6, LOW);  
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);

    lastDispenseMs = millis();

    // Debounce so sensor doesn't trigger the motor again for a little.
    delay(1000);
  }  

  delay(1000);
}
