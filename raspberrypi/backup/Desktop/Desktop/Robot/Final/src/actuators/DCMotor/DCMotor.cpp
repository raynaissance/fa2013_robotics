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
}

void DCMotor::stop()
{
  	softPwmWrite (motorA, 0); // set pwm value
 	softPwmWrite (motorB, 0); // set pwm value
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