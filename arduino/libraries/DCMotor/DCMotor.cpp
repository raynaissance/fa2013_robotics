#include "Arduino.h"
#include "DCMotor.h"

DCMotor::DCMotor() {}

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

void DCMotor::go(int speed)
{
	speed = speed*255/100;
	
	if (speed > 0)
	{
		digitalWrite(motorA, HIGH);
		digitalWrite(motorB, LOW);
	} else {
		digitalWrite(motorA, LOW);
		digitalWrite(motorB, HIGH);
	}
	analogWrite(motorE, speed);
}