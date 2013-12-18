#include "Arduino.h"
#include "SonarSensor.h"

SonarSensor::PingSensor(int pin)
{
	trigger = sensorPin;
    lastDistance = readCentimeters();
}

long SonarSensor::readDuration()
{	
	pinMode(trigger, OUTPUT);
  	digitalWrite(trigger, LOW);
  	delayMicroseconds(2);
  	digitalWrite(trigger, HIGH);
  	delayMicroseconds(5);
  	digitalWrite(trigger, LOW);
  	
  	pinMode(trigger, INPUT);
  	return pulseIn(trigger, HIGH);
}

long SonarSensor::readInches()
{
  	return readDuration() / 74 / 2;
}

long SonarSensor::readCentimeters()
{
	return readDuration() / 29 / 2;
}

long SonarSensor::ping()
{
    lastDistance = readCentimeters();
    return lastDistance;
}