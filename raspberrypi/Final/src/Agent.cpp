#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "Robot.h"

#define ARC 1
#define DOCK 2
#define ROCKET 3

#define END 0
#define LEFT 1
#define RIGHT 2
 
int main(void) {
	
	Robot* bot = new Robot();
	int counter = 0;
	int distance = -1; 
	int lookDir = 0;
	bool stop = false;
	int speed = -50;

	int pathIndex = 0;
	int pathArc[4] = {LEFT, RIGHT, RIGHT, END};

	int state = ARC;

	while(true) {

		if(state == ARC) {
			distance = bot->lookForward();
			if(distance < 23) {
				bot->stop();

				/*if(pathArc[pathIndex] == LEFT) {
					bot->spinLeft(50, 50);
				} else if(pathArc[pathIndex] == RIGHT) {
					bot->spinRight(50, 50);
				} else {
					state = DOCK;
				}*/
			} else {
				/*bot->moveForward(speed);
				printf("Speed: %d", speed);
				*/
				//bot->spinRight(50, 50);
				bot->moveForward(speed);
				delay(100);
			}
			
			//state = DOCK;
		}

		if(state == DOCK) {
			//bot->stop();
		}

		//bot->spinRight(50, 50);
		//stop = true;
		counter++;
	}
 
 return 0;
}
