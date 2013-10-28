#include "Arduino.h"
#include "DCMotor.h"

DCMotor::DCMotor(int mA, int mB, int mE)
{
	motorA = mA;
	motorB = mB;
	motorE = mE;

	pinMode(motorA, OUTPUT);
    pinMode(motorB, OUTPUT);
    pinMode(motorE, OUTPUT);
}

void DCMotor::stop()
{
  	digitalWrite(motorE, LOW);
}

void DCMotor::setWheelSpeed(int speed, int direction)
{
	if (direction == FORWARD)
	{
		digitalWrite(motorA, HIGH);
		digitalWrite(motorB, LOW);
	} else {
		digitalWrite(motorA, LOW);
		digitalWrite(motorB, HIGH);
	}
	analogWrite(motorE, speed);
}