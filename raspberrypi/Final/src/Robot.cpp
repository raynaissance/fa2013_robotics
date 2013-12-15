#include "Robot.h"
extern "C" {
#include <wiringPi.h>
}
#include <softPwm.h>

Robot::Robot()
{
	wiringPiSetup();

	// Initialize DCMotors for left and right wheels
	leftWheel = new DCMotor(0,1);
	rightWheel = new DCMotor(3,4);

	// TODO:: Initialize vision system: servo, sonar, and camera
	//visionServo = new ServoMotor();

	// TODO:: Initialize claw system: servo, flex senesor

	// TODO:: Initialize compass
}

void Robot::stop()
{
  	leftWheel->stop();
  	rightWheel->stop();
}

void Robot::moveForward(int velocity)
{
	leftWheel->moveWheel(abs(velocity));
	rightWheel->moveWheel(abs(velocity));
}

void Robot::moveBackward(int velocity)
{

}

void Robot::turnLeft(int speed)
{

}

void Robot::turnRight(int speed)
{

}

void Robot::spinLeft(int leftSpeed, int rightSpeed)
{

}

void Robot::spinRight(int leftSpeed, int rightSpeed)
{

}

void Robot::lookForward()
{

}

void Robot::lookLeft()
{

}

void Robot::lookRight()
{

}