#include "SonarSensor.h"

SonarSensor::SonarSensor(int pin)
{
    /*trigger = pin;
    pinMode(trigger, OUTPUT);
    digitalWrite(trigger, LOW);
    delay(30);
    digitalWrite(trigger, HIGH);
    delay(50);
    digitalWrite(trigger, LOW);
    pinMode(trigger, INPUT);
 
    //Wait for echo start
    while(digitalRead(trigger) == LOW);

    //Wait for echo end
    long startTime = micros();
    while(digitalRead(trigger) == HIGH);
    long travelTime = micros() - startTime;

    //Get distance in cm
    int distance = travelTime / 58;

    return distance;*/
}

void SonarSensor::ping()
{
    /*softPwmWrite (motorA, 0); // set pwm value
    softPwmWrite (motorB, 0); // set pwm value*/
}
