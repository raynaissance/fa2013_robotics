#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "Robot.h"
 
int main(void) {

	
	Robot* bot = new Robot();
	int counter = 0;
	int distance = -1; 

	while(true) {
		if(counter > 100000) {
			bot->stop();
		} else {
			bot->moveForward((int)((float)counter/100000*100));
			if (counter % 1000 == 0)
			{
				printf("Speed: %d", (int)((float)counter/100000*100));
			}
		}

		if(counter%1000 == 0) {
			distance = bot->lookForward();
			printf(", Distance: %dcm\n", distance);
		}
		counter++;
	}
 
 return 0;
}