#include "Arduino.h"
#include "MotorController.h"
#include "../DCMotor/DCMotor.cpp"

MotorController::MotorController() {}

MotorController::MotorController(int leftA, int leftB, int leftE, int rightA, int rightB, int rightE)
{
	leftWheel = new DCMotor(leftA, leftB, leftE);
	rightWheel = new DCMotor(rightA, rightB, rightE);
}

void MotorController::stop()
{
  	leftWheel->stop();
  	rightWheel->stop();
}

void MotorController::forward(int speed) 
{
	leftWheel->go(speed, FORWARD);
	rightWheel->go(speed, FORWARD);
}

void MotorController::reverse(int speed)
{
	leftWheel->go(speed, REVERSE);
	rightWheel->go(speed, REVERSE);
}

void MotorController::turnLeft(int speedL, int speedR)
{
	leftWheel->go(speedL, FORWARD);
	rightWheel->go(speedR, FORWARD);
}

void MotorController::turnRight(int speedL, int speedR)
{
	leftWheel->go(speedL, FORWARD);
	rightWheel->go(speedR, FORWARD);
}

void MotorController::spinLeft(int speed)
{
	leftWheel->go(speed, REVERSE);
	rightWheel->go(speed, FORWARD);
}

void MotorController::spinRight(int speed)
{
	leftWheel->go(speed, FORWARD);
	rightWheel->go(speed, REVERSE);
}