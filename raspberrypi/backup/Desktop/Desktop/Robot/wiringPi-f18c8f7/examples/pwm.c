/*
 * pwm.c:
 *	This tests the hardware PWM channel.
 *
 * Copyright (c) 2012-2013 Gordon Henderson. <projects@drogon.net>
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void)
{
  /*int bright ;

  printf ("Raspberry Pi wiringPi PWM test program\n") ;

  if (wiringPiSetup () == -1)
    exit (1) ;

  pinMode (1, PWM_OUTPUT) ;

  for (;;)
  {
    for (bright = 0 ; bright < 1024 ; ++bright)
    {
      pwmWrite (1, bright) ;
      delay (1) ;
    }

    for (bright = 1023 ; bright >= 0 ; --bright)
    {
      pwmWrite (1, bright) ;
      delay (1) ;
    }
  }*/

  //// start Joseph's code
    FILE *fp;
 fp = fopen("/dev/servoblaster", "w");
 if (fp == NULL) {
 printf("Error opening file\n");
 exit(0);
 }
 while (1) {
       fprintf(fp, "0=182\n"); //Servo#0, Counter Clockwise
       fprintf(fp, "1=182\n"); //Servo#1, Counter Clockwise
       delay(1000);
       fflush(fp);
       fprintf(fp, "0=152\n"); //Stop
       fprintf(fp, "1=152\n"); //Stop
       delay(1000);
       fflush(fp);
       fprintf(fp, "0=100\n"); //Clockwise
       fprintf(fp, "1=100\n"); //Clockwise
       delay(1000);
       fflush(fp);
       fprintf(fp, "0=152\n"); //Stop
       fprintf(fp, "1=152\n"); //Stop
       delay(1000);
       fflush(fp);
 }
 fclose(fp); 
  //// end Joseph's code

  return 0 ;
}
