#include "DCMotor.h"

DCMotor::DCMotor(int mA, int mB)
{
	motorA = mA;
	motorB = mB;
	int test1, test2;

 	pinMode(motorA, PWM_OUTPUT); //setup hardware pwm
 	pinMode(motorB, PWM_OUTPUT); //setup hardware pwm  

 	test1 = softPwmCreate (motorA, 100, 100); // (pin, initial value, pwm range)
 	test2 = softPwmCreate (motorB, 100, 100); // (pin, initial value, pwm range)

	if (test1 != 0 || test2 != 0)
	{
		printf("Warning: error creating soft PWM! \n");
		exit(1);
	}
}

void DCMotor::stop()
{
  	pinMode(motorA, OUTPUT);
 	pinMode(motorB, OUTPUT);
 	digitalWrite(motorA, LOW);
 	digitalWrite(motorB, LOW);
 	pinMode(motorA, PWM_OUTPUT);
 	pinMode(motorB, PWM_OUTPUT); 
}

void DCMotor::moveWheel(int velocity)
{
	if (velocity > 0)
	{
		softPwmWrite (motorA, velocity);
		softPwmWrite (motorB, 0);
	} else {
		softPwmWrite (motorA, 0);
		softPwmWrite (motorB, velocity);
	}
}