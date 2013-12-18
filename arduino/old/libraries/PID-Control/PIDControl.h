#ifndef PIDControl_h
#define PIDControl_h

#include "Arduino.h"

class PIDControl
{
  public:
	PIDControl_h(int pin);
    float update(float sensorData);
  private:
    int P;
    int I;
    int D;
    float Kp;
    float Ki;
    float Kd;
    float integralSum;
    int goalDistance; // in centimeters

    float prevSensorData;
};

#endif
