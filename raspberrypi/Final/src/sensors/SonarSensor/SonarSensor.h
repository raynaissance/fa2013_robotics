#ifndef SonarSensor_h
#define SonarSensor_h

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

class SonarSensor
{
  public:
    SonarSensor(int pin);
    int ping();
  private:
    int trigger;
    int lastDistance;
};

#endif