#ifndef SonarSensor_h
#define SonarSensor_h

#include "Arduino.h"

class SonarSensor
{
	public:
		SonarSensor(int pin);
		long ping();
		long readInches();
		long readCentimeters();
	private:
		int trigger;
    	int lastDistance;
		long readDuration();
};

#endif