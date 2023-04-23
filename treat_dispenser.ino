/*
  Stepper Motor Demonstration 3
  Stepper-Demo3.ino
  Demonstrates NEMA 17 Bipolar Stepper with L298N Driver
  Uses Potentiometer on Analog Input A0
  Uses Arduino Stepper Library

  DroneBot Workshop 2018 
  https://dronebotworkshop.com
*/

// Include the Arduino Stepper Library
#include <Stepper.h>

// Define Constants

// Number of steps per output rotation
const int STEPS_PER_REV = 200;
const int RADIO_RECIEVER = 3;

// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to L298N Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-2-3-4 for proper step sequencing

Stepper stepper_NEMA17(STEPS_PER_REV, 6, 7, 8, 9);

void setup() {
  pinMode(RADIO_RECIEVER, INPUT);
  stepper_NEMA17.setSpeed(5);
}

void loop() {
  // read the sensor value:
  int pressed = digitalRead(RADIO_RECIEVER);
  if (pressed == LOW) {
    return;
  }  

  stepper_NEMA17.step(STEPS_PER_REV / 16);
  digitalWrite(6, LOW);  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
 
  delay(1000);
}