#ifndef ServoMotor_h
#define ServoMotor_h

#include <stdio.h>
#include <stdlib.h>
#include "wiringPi.h"

class ServoMotor
{
public:
	ServoMotor(int servoNumber);
private:
	int servoNum;
	FILE *fp;
	int currentAngle;
}

#endif