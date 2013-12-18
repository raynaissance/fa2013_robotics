#include "Arduino.h"
#include "MotorController.h"

MotorController::MotorController(int leftA, int leftB, int leftE, int rightA, int rightB, int rightE)
{
	this->leftWheel = new DCMotor(int leftA, int leftB, int leftE);
	this->rightWheel = new DCMotor(int rightA, int rightB, int rightE);
}

void MotorController::stop()
{
  	leftWheel.stop();
  	rightWheel.stop();
}

void MotorController::forward(int speed) 
{
	leftWheel.setWheelSpeed(speed, FORWARD);
	rightWheel.setWheelSpeed(speed, FORWARD);
}

void MotorController::reverse(int speed)
{
	leftWheel.setWheelSpeed(speed, REVERSE);
	rightWheel.setWheelSpeed(speed, REVERSE);
}

void MotorController::turnLeft(int speedL, int speedR)
{
	leftWheel.setWheelSpeed(speedL, FORWARD);
	rightWheel.setWheelSpeed(speedR, FORWARD);
}

void MotorController::turnRight(int speedL, int speedR)
{
	leftWheel.setWheelSpeed(speedL, FORWARD);
	rightWheel.setWheelSpeed(speedR, FORWARD);
}

void MotorController::spinLeft(int speed)
{
	leftWheel.setWheelSpeed(speed, REVERSE);
	rightWheel.setWheelSpeed(speed, FORWARD);
}

void MotorController::spinRight(int speed)
{
	leftWheel.setWheelSpeed(speed, FORWARD);
	rightWheel.setWheelSpeed(speed, REVERSE);
}