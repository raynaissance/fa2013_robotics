#include "Arduino.h"
#include "Robot.h"
#include <Servo.h>


void setup() {
  // put your setup code here, to run once:
  Robot bot = Robot();
  Serial.begin(9600);
  bot.lookForward();
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
