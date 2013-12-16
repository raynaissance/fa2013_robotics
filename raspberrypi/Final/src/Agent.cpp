#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "Robot.h"
 
int main(void) {

	
	Robot* bot = new Robot();
	int counter = 0;
	int distance = -1; 
	int lookDir = 0;

	while(true) {
		if(counter > 100000) {
			bot->stop();
		} else {
			if (counter % 1000 == 0)
			{
				bot->moveForward((int)((float)counter/100000*100));
				printf("Speed: %d", (int)((float)counter/100000*100));
			}
		}

		if(counter%1000 == 0) {
			if (lookDir % 4 == 0) { distance = bot->lookLeft(); printf("Left"); }
			if (lookDir % 4 == 1 || lookDir % 4 == 3) { distance = bot->lookForward(); printf("Forward"); }
			if (lookDir % 4 == 2) { distance = bot->lookRight(); printf("Right"); }
			
			lookDir++;
			printf(", Distance: %dcm\n", distance);
		}
		counter++;
	}
 
 return 0;
}