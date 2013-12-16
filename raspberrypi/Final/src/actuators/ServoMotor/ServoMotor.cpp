#include "ServoMotor.h"

ServoMotor::ServoMotor(int servoNumber)
{
	servoNum = servoNumber;
	currentAngle = -1;

	fp = fopen("/dev/servoblaster", "w");
	if (fp == NULL)
	{
		printf("Error opening servoblaster file!\n");
		exit(1);
	}
}

void ServoMotor::goToAngle(int angle)
{
	fprintf(fp, "%d=%d\n", servoNum, angle);
	fprintf(fp, "1=100\n");
	delay(1000);
	currentAngle = angle;
		
	fflush(fp);
}