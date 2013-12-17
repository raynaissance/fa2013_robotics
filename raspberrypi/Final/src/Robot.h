#ifndef Robot_h
#define Robot_h

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "./actuators/ServoMotor/ServoMotor.h"
#include "./actuators/DCMotor/DCMotor.h"
#include "./sensors/SonarSensor/SonarSensor.h"

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

    DCMotor *leftWheel;
    DCMotor *rightWheel;
    ServoMotor *clawServo;
    ServoMotor *sonarServo;
    SonarSensor *sonar;
    /*Camera camera;
    FlexSensor flex;
    CompassModule compass;*/
  private:
    // no private members yet
};

#endif
