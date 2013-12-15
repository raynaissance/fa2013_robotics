#ifndef DCMotor_h
#define DCMotor_h

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

#define FORWARD 1
#define REVERSE 0
#define STOPPED 2

class DCMotor
{
  public:
    DCMotor(int mA, int mB);
    void stop();
    void moveWheel(int mVelocity);
  private:
    int motorA;
    int motorB;
};

#endif