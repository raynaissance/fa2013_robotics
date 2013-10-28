#ifndef DCMotor_h
#define DCMotor_h

#include "Arduino.h"

#define FORWARD 1
#define REVERSE 0
#define STOPPED 2

class DCMotor
{
  public:
	DCMotor(int mA, int mB, int mE);
    void stop();
    void setDirection(int speed, int direction);
  private:
	int motorA;
	int motorB;
	int motorE;
    int motorSpeed;
    int motorDirection;
};

#endif
