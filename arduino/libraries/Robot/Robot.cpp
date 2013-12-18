#include "Arduino.h"
#include "Robot.h"

Robot::Robot()
{
	// Initialize DCMotors for left and right wheels
	leftWheel = new DCMotor(7,8,6);
	rightWheel = new DCMotor(12,13,5);

	// TODO:: Initialize vision system: servo, sonar, and camera
	sonarServo.attach(3);
	sonar = new PingSensor(2);

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
	leftWheel->go(abs(velocity), FORWARD);
	rightWheel->go(abs(velocity));
}

void Robot::moveBackward(int velocity)
{
	leftWheel->go(-1*abs(velocity));
	rightWheel->go(-1*abs(velocity));
}

void Robot::turnLeft(int speed)
{

}

void Robot::turnRight(int speed)
{

}

void Robot::spinLeft(int leftSpeed, int rightSpeed)
{
	leftWheel->go((-1)*leftSpeed);
	rightWheel->go(rightSpeed);

}

void Robot::spinRight(int leftSpeed, int rightSpeed)
{
	//leftWheel->moveWheel(leftSpeed);
	rightWheel->go(-rightSpeed);
	//delay(300);
}

long Robot::lookForward()
{
	sonarServo.write(90);
	delay(500);
	return sonar->ping();
}

long Robot::lookLeft()
{
	sonarServo.write(0);
	delay(500);
	return sonar->ping();
}

long Robot::lookRight()
{
	sonarServo.write(180);
	delay(500);
	return sonar->ping();
}