#ifndef PingSensor_h
#define PingSensor_h

#include "Arduino.h"

class PingSensor
{
	public:
		PingSensor(int pin);
		long readInches();
		long readCentimeters();
	private:
		int pingPin;
		long readDuration();
};

#endif