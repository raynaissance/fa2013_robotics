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
    void ping();
    //int getDistance();
  private:
    int trigger;
    int lastRawData;
    int lastDistance;
};

#endif