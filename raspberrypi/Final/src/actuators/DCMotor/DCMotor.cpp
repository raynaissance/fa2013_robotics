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
  	softPwmWrite(motorA, 100);
	softPwmWrite(motorB, 100);
}

void DCMotor::moveWheel(int velocity)
{
	if (velocity > 0)
	{
		softPwmWrite (motorA, 100 - velocity);
		softPwmWrite (motorB, 100);
	} else {
		softPwmWrite (motorB, 100 + velocity);
		softPwmWrite (motorA, 100);
	}
}