#include "Arduino.h"
#include "IRSensor.h"

IRSensor::IRSensor(int pin)
{
	sensorPin = pin;
	pinMode(sensorPin, INPUT);
}

float IRSensor::voltageToDistance() {
  int input = analogRead(sensorPin);
  float inputVoltage = input*0.0048828125;
  float points [14][2] = {
     {2.5, 20},
     {2.0, 30},
     {1.5, 40},
     {1.25, 50},
     {1.05, 60},
     {0.88, 70},
     {0.82, 80},
     {0.7, 90},
     {0.65, 100},
     {0.6, 110},
     {0.55, 120},
     {0.48, 130},
     {0.4, 140},
     {0.35, 150}
  };
  
  int sample = -1;
  
  if(inputVoltage <= points[0][0] && inputVoltage > points[1][0]) {
    sample = 0; 
  } else if(inputVoltage <= points[1][0] && inputVoltage > points[2][0]) {
    sample = 1;
  } else if(inputVoltage <= points[2][0] && inputVoltage > points[3][0]) {
    sample = 2;
  } else if(inputVoltage <= points[3][0] && inputVoltage > points[4][0]) {
    sample = 3;
  } else if(inputVoltage <= points[4][0] && inputVoltage > points[5][0]) {
    sample = 4;
  } else if(inputVoltage <= points[5][0] && inputVoltage > points[6][0]) {
    sample = 5;
  } else if(inputVoltage <= points[6][0] && inputVoltage > points[7][0]) {
    sample = 6;
  } else if(inputVoltage <= points[7][0] && inputVoltage > points[8][0]) {
    sample = 7;
  } else if(inputVoltage <= points[8][0] && inputVoltage > points[9][0]) {
    sample = 8;
  } else if(inputVoltage <= points[9][0] && inputVoltage > points[10][0]) {
    sample = 9;
  } else if(inputVoltage <= points[10][0] && inputVoltage > points[11][0]) {
    sample = 10;
  } else if(inputVoltage <= points[11][0] && inputVoltage > points[12][0]) {
    sample = 11;
  } else if(inputVoltage <= points[12][0] && inputVoltage > points[13][0]) {
    sample = 12;
  } else {
    return sample;
  }

  return (inputVoltage-points[sample+1][0])/((points[sample+1][0]-points[sample][0])/10) + points[sample+1][1];
}