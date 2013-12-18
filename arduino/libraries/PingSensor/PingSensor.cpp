#include "Arduino.h"
#include "PingSensor.h"

PingSensor::PingSensor(int sensorPin)
{
	pingPin = sensorPin;
}

long PingSensor::readDuration()
{	
	pinMode(pingPin, OUTPUT);
  	digitalWrite(pingPin, LOW);
  	delayMicroseconds(2);
  	digitalWrite(pingPin, HIGH);
  	delayMicroseconds(5);
  	digitalWrite(pingPin, LOW);
  	
  	pinMode(pingPin, INPUT);
  	return pulseIn(pingPin, HIGH);
}

long PingSensor::readInches()
{
  	return readDuration() / 74 / 2;
}

long PingSensor::readCentimeters()
{
	return readDuration() / 29 / 2;
}