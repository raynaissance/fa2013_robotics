#ifndef IRSensor_h
#define IRSensor_h

#include "Arduino.h"

class IRSensor
{
  public:
	IRSensor(int pin);
    float voltageToDistance();
  private:
    int sensorPin;
    int val;
};

#endif
