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
	fprintf(fp, static_cast<ostringstream*>( &(ostringstream() << servoNum) )->str() + "=" + static_cast<ostringstream*>( &(ostringstream() << angle) )->str() + "\n");
	delay(100);
	delay(abs(angle - currentAngle) * 2);
	currentAngle = angle;
}