#ifndef MotorController_h
#define MotorController_h

#include "Arduino.h"
#include "../DCMotor/DCMotor.h"

class MotorController
{
  public:
	MotorController(int leftA, int leftB, int leftE, int rightA, int rightB, int rightE);
    void stop();
    void forward(int speed);
    void reverse(int speed);
    void turnLeft(int speedL, int speedR);
    void turnRight(int speedL, int speedR);
    void spinLeft(int speed);
    void spinRight(int speed);
  private:
	DCMotor leftWheel;
	DCMotor rightWheel;
};

#endif
