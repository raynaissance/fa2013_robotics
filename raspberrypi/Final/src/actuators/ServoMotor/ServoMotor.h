#ifndef ServoMotor_h
#define ServoMotor_h

#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <iostream>
#include "wiringPi.h"

class ServoMotor
{
public:
	ServoMotor(int servoNumber);
	void goToAngle(int angle);
private:
	int servoNum;
	FILE *fp;
	int currentAngle;
};

#endif