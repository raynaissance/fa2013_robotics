#include <stdio.h>
#include <stdlib.h>
#include "wiringPi.h"
int main(void)
{
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
 return 0;
}
