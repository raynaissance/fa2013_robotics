#include "Arduino.h"
#include "PIDControl.h"

PIDControl::PIDControl(float k_p, float k_i, float k_d, int distance='50')
{
  float Kp = 1.8f;
  float Kd = 1.2f;
  float Ki = 0.3f;

  float prevSensorData = 0;
  int goalDistance = distance; // cm
  float integralSum = 0;
}

float PIDControl::update(float sensorData)
{
  int input = analogRead(sensorPin);
  float inputVoltage = input*0.0048828125;


  return (inputVoltage-points[sample+1][0])/((points[sample+1][0]-points[sample][0])/10) + points[sample+1][1];
}