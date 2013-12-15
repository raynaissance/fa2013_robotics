#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "Camera.cpp"

void start();
int send(char*);
int receive();

char buffer[10];
int fd;

int redObjectX;
int redObjectY;
Camera* myCamera;

int main() {
	/*struct termios serial;
    if (argc == 1) {
        printf("Usage: %s [device]\n\n", argv[0]);
        return -1;
    }
    printf("Opening %s\n", argv[1]);
    fd = open(argv[1], O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror(argv[1]);
        return -1;
    }
    if (tcgetattr(fd, &serial) < 0) {
        perror("Getting configuration");
        return -1;
    }
    // Set up Serial Configuration
    serial.c_iflag = 0;
    serial.c_oflag = 0;
    serial.c_lflag = 0;
    serial.c_cflag = 0;
    serial.c_cc[VMIN] = 0;
    serial.c_cc[VTIME] = 0;
    serial.c_cflag = B115200 | CS8 | CREAD;
    tcsetattr(fd, TCSANOW, &serial); // Apply configuration*/

	myCamera = new Camera();
	if(myCamera->initCapture()) {
		start();
		
	} else {
		printf("RobotVision: Error initializing capture\n");
	}
	myCamera->turnOff();
	delete myCamera;
	//close(fd);
}

void start() {
    myCamera->captureImg();
    redObjectX = myCamera->getObjectX();
    int deltaX = 0;

    while(true) {
        if(myCamera->captureImg() == false) {
        	break;
        }

        deltaX = redObjectX - myCamera->getObjectX();

        if(abs(deltaX) > 30) {
            if(deltaX < 0){
                //send("L");
                printf("L");
            }
            if(deltaX > 0) {
                //send("R");
                printf("R");
            }
            redObjectX = myCamera->getObjectX();
        }
        
        receive(); 
    }
}

int send(char* str) {
    printf("Sending: %s\n", str);
    int wcount = write(fd, str, strlen(str));
    if (wcount < 0) {
        perror("Write");
        return -1;
    }
    else {
        printf("Sent %d characters\n", wcount);
    }
}

int receive() {
    int rcount = read(fd, buffer, sizeof(buffer));
    if (rcount < 0) {
        perror("Read");
        return -1;
    }
    else {
        printf("Received %d characters\n", rcount);
    }
    buffer[rcount] = '\0';
    printf("Received: %s\n", buffer); 
}