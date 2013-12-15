#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "Robot.h"
 
int main(void) {

	
	Robot* bot = new Robot();
	int counter = 0;

	while(true) {
		if(counter > 10000) {
			bot->stop();
		} else {
			bot->moveForward(70);
		}
		counter++;
	}
 
 return 0;
}