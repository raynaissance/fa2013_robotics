#include "Arduino.h"
#include "Robot.h"

Robot::Robot()
{
	wiringPiSetup();

	// Initialize DCMotors for left and right wheels
	leftWheel = new DCMotor(7,8,6);
	rightWheel = new DCMotor(12,13,5);

	// TODO:: Initialize vision system: servo, sonar, and camera
	sonarServo.attach(3);
	sonar = new SonarSensor(2);

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
	leftWheel->moveMotor(abs(velocity));
	rightWheel->moveMotor(abs(velocity));
}

void Robot::moveBackward(int velocity)
{
	if(velocity > 0) {
		leftWheel->moveMotor(-velocity);
		rightWheel->moveMotor(-velocity);
	} else {
		leftWheel->moveMotor(velocity);
		rightWheel->moveMotor(velocity);
	}
}

void Robot::turnLeft(int speed)
{

}

void Robot::turnRight(int speed)
{

}

void Robot::spinLeft(int leftSpeed, int rightSpeed)
{
	leftWheel->moveMotor((-1)*leftSpeed);
	rightWheel->moveMotor(rightSpeed);

}

void Robot::spinRight(int leftSpeed, int rightSpeed)
{
	//leftWheel->moveWheel(leftSpeed);
	rightWheel->moveMotor(-rightSpeed);
	//delay(300);
}

long Robot::lookForward()
{
	return sonar->ping();
}

long Robot::lookLeft()
{
	return sonar->ping();
}

long Robot::lookRight()
{
	return sonar->ping();
}