#ifndef Robot_h
#define Robot_h

#include "Arduino.h"
#include "../DCMotor/DCMotor.h"
#include <Servo.h> 

#define FORWARD 1
#define REVERSE 0
#define STOPPED 2

class Robot
{
  public:
    Robot();
    void stop();
    void moveForward(int velocity);
    void moveBackward(int velocity);
    void turnLeft(int speed);
    void turnRight(int speed);
    void spinLeft(int leftSpeed, int rightSpeed);
    void spinRight(int leftSpeed, int rightSpeed);
    int lookForward();
    int lookLeft();
    int lookRight();

    DCMotor* leftWheel;
    DCMotor* rightWheel;
    Servo sonarServo;
    SonarSensor* sonar;

    /*
    FlexSensor flex;
    CompassModule compass;*/
    
  private:
    // no private members yet
};

#endif