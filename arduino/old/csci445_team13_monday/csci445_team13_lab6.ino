#include <Servo.h>
#include <MotorController.h>

#define ADVANCE 0
#define RETREAT 1
#define FINISHED 2

int flexSensorPin = A0; //analog pin 0
int clawPin = 10;
Servo clawServo; // 85 = closed, 0 = open
int flexBaseline = -1;
int flexTolerance = 12;
int state = ADVANCE;

MotorController rightMotor = MotorController(6,7,5);
MotorController leftMotor = MotorController(2,4,3);


void setup()
{
  pinMode(flexSensorPin, INPUT);
  clawServo.attach(clawPin);
  Serial.begin(9600);
  delay(100);
  flexBaseline = analogRead(flexSensorPin)/10;

  clawServo.write(0);
}

void loop()
{
  // How much the sensor has bent from equilibrium
  int flexSensorDiff = flexBaseline - analogRead(flexSensorPin)/10;
  bool flexSensorTripped = abs(flexSensorDiff) > flexTolerance;

  if (state == ADVANCE)
  {
    leftMotor.setWheelSpeed(240, FORWARD);
    rightMotor.setWheelSpeed(145, FORWARD);

    if (flexSensorTripped)
    {
      leftMotor.stop();
      rightMotor.stop();

      // Close claw
      clawServo.write(85);
      delay(500);
      state = RETREAT;
    }
    
    return;
  }

  if (state == RETREAT)
  {
    leftMotor.setWheelSpeed(210, REVERSE);
    rightMotor.setWheelSpeed(200, REVERSE);
    delay(20*1000);
    leftMotor.stop();
    rightMotor.stop();
    
    state = FINISHED;
    
    return;
  }
}




