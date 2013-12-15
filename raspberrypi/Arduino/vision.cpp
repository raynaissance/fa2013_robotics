#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "Vision.h"

Vision::Vision(int argc, char* argv[]) {
    /*struct termios serial;
    char buffer[10];
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
    cam = new Camera();

    start();
    //close(fd);
}

Vision::start() {
    cam.captureImg();
    redObjectX = cam.getObjectX();

    while(true) {
        // Attempt to send and receive
        cam.captureImg();
        deltaX = redObjectX - cam.getObjectX();

        if(abs(deltaX) > 30) {
            if(deltaX < 0){
                //send("L");
                printf("L\n");
            }
            if(deltaX > 0) {
                //send("R");
                printf("R\n");
            }
            redObjectX = cam.getObjectX();
        }
        
        receive(); 
    }
}

Vision::stop() {
    cam.turnOff();
}

Vision::send() {
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

Vision::receive() {
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