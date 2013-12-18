#ifndef DCMotor_h
#define DCMotor_h

#include "Arduino.h"

class DCMotor
{
  public:
    DCMotor();
    DCMotor(int mA, int mB, int mE);
    void stop();
    void go(int speed);
  private:
  	int motorA;
  	int motorB;
  	int motorE;
    int motorSpeed;
};

#endif
