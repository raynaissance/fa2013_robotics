#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
 
void setup() {
    wiringPiSetup();
 	pinMode(1, PWM_OUTPUT); //setup hardware pwm
	pinMode(6, PWM_OUTPUT);
}
 
int main(void) {
 	int test1, test2;
 
 	setup();
 	test1 = softPwmCreate (1, 100, 100); // (pin, initial value, pwm range)
 	test2 = softPwmCreate (6, 100, 100); // (pin, initial value, pwm range)
 
 	while(1) {
 		softPwmWrite (1, 100); // set pwm value
 		softPwmWrite (6, 0); // set pwm value
	}

//	softPwmWrite(1, 0);
//	softPwmWrite(3, 0);
 

	return 0;
}
