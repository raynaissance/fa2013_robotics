#include "SonarSensor.h"

SonarSensor::SonarSensor(int pin)
{
    trigger = pin;
}


/**
@method ping
@param None
@return {long} Returns distance (in centimeters) from a detected object
*/
int SonarSensor::ping()
{
    pinMode(trigger, OUTPUT);
    digitalWrite(trigger, LOW);
    delay(30);
    digitalWrite(trigger, HIGH);
    delay(50);
    digitalWrite(trigger, LOW);
    pinMode(trigger, INPUT);
 
    // Wait for echo start
    while(digitalRead(trigger) == LOW);

    // Wait for echo end
    long startTime = micros();
    while(digitalRead(trigger) == HIGH);
    long travelTime = micros() - startTime;

    // Get distance in cm
    int distance = (int)travelTime / 58;

    lastDistance = distance;
    return distance;
}