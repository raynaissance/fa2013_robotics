#include "Robot.h"

Robot::Robot()
{
	wiringPiSetup();

	// Initialize DCMotors for left and right wheels

	leftWheel = new DCMotor(0,19);
	rightWheel = new DCMotor(4,5);

	// TODO:: Initialize vision system: servo, sonar, and camera
	sonar = new SonarSensor(7);

	// TODO:: Initialize claw system: servo, flex senesor
	clawServo = new ServoMotor(1); // Servo 1 = wiringPi pin 7

	// TODO:: Initialize compass
}

void Robot::stop()
{
  	leftWheel->stop();
  	rightWheel->stop();
}

void Robot::moveForward(int velocity)
{
	leftWheel->moveWheel(velocity);
	rightWheel->moveWheel(velocity);
}

void Robot::moveBackward(int velocity)
{
	if(velocity > 0) {
		leftWheel->moveWheel(-velocity);
		rightWheel->moveWheel(-velocity);
	} else {
		leftWheel->moveWheel(velocity);
		rightWheel->moveWheel(velocity);
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
	leftWheel->moveWheel((-1)*leftSpeed);
	rightWheel->moveWheel(rightSpeed);

}

void Robot::spinRight(int leftSpeed, int rightSpeed)
{
	//leftWheel->moveWheel(leftSpeed);
	rightWheel->moveWheel(-rightSpeed);
	//delay(300);
}

int Robot::lookForward()
{
	return sonar->ping();
}

int Robot::lookLeft()
{
	return sonar->ping();
}

int Robot::lookRight()
{
	return sonar->ping();
}

void Robot::openClaw()
{
	clawServo->goToAngle(15);
}

void Robot::closeClaw()
{
	clawServo->goToAngle(0);
}
}
}
