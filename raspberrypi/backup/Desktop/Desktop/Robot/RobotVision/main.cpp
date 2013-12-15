#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "time.h"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
// include the necessary libraries
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

IplImage* imgTracking;
int lastX = -1;
int lastY = -1;
int objX = -1;
char buffer[10];
int fd = -1;

int send(char* str);
IplImage* GetThresholdedImage(IplImage* imgHSV);
void trackObject(IplImage* imgThresh);

int main(int argc, char* argv[]) {
    struct termios serial;
    
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
    serial.c_cflag = B9600 | CS8 | CREAD;
    tcsetattr(fd, TCSANOW, &serial); // Apply configuration

    CvCapture* capture = 0;
 
    capture = cvCaptureFromCAM( CV_CAP_ANY );
    if (cvWaitKey(60) != -1) {
        cout << "Input" << endl;
    }
    if( !capture )
    {
        fprintf(stderr, "failed to initialize video capture\n");
        return -1;
    }
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 160 );
 
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 120 );
 
    IplImage* frame = 0;
    //IplImage* frame1 = 0;
 
    cvNamedWindow("Video");
    cvNamedWindow("Ball");
//    cvNamedWindow("Trace");
 
    if ((frame = cvQueryFrame(capture))) {
        cvShowImage("Video", frame);
    }
    if (cvWaitKey(8000) != -1) {
        cout << "Input" << endl;
    }
    //IplImage* imgHSV = cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,3);
    IplImage* imgHSV = 0;
    IplImage* imgThresh = 0;
    imgTracking = cvCreateImage(cvSize(160, 120),IPL_DEPTH_8U, 3);
    cvZero(imgTracking); //covert the image, 'imgTracking' to black
    int time = 0;
    int deltaX = 0;

    while(true) {
        // Look for the RED
            cout << "time = " << time++ << endl;
     
            //frame = cvLoadImage("/Users/chi-anchen/Pictures/Pics/test.jpg", CV_LOAD_IMAGE_UNCHANGED);
            if ((frame = cvQueryFrame(capture))) {
                //cvShowImage("Video", frame);
                cout << "Got it" << endl;
            }
            if (cvWaitKey(100) != -1) {
                cout << "Input" << endl;
                break;
            }
            frame = cvCloneImage(frame);
            //cvCopy(frame, frame);
            //cvReleaseImage(&imgHSV);
     
            cvSmooth(frame, frame, CV_GAUSSIAN,3,3); //smooth the original image using Gaussian kernel
            imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
            //imgHSV = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
     
            cvCvtColor(frame, imgHSV, CV_BGR2HSV); //Change the color format from BGR to HSV, Before I used CV_RGB2GRAY which is wrong
            imgThresh = GetThresholdedImage(imgHSV);
     
            cvSmooth(imgThresh, imgThresh, CV_GAUSSIAN,3,3); //smooth the binary image using Gaussian kernel
            trackObject(imgThresh);
     
            cvAdd(frame, imgTracking, frame);
            cvShowImage("Video", frame);
            cvShowImage("Ball", imgThresh);

        // Attempt to send and receive
        if(objX != lastX) {
            if(lastX > 0) {
                if(lastX < 40) {
                    send("L");
                    cout << "GOOOOOO LEFT!!" << endl;
                } else if(lastX > 120) {
                    send("R");
                    cout << "GOOOOOO RIGHT!!" << endl;
                } else {
                    if(objX < 60 || objX > 100) {
                        send("S");
                        cout << "STOOOOOOOPPPPP!!" << endl;
                    }
                }
                objX = lastX;
            }
        }
        //send("S");
        //cout << "STOOOOOOOPPPPP!!" << endl;
    }
    cvReleaseImage(&frame);
    cvReleaseImage(&imgHSV);
    cvReleaseImage(&imgThresh);
    cvDestroyAllWindows();
    cvReleaseImage(&imgTracking);
    cvReleaseCapture(&capture);
    close(fd);
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

//This function threshold the HSV image and create a binary image
IplImage* GetThresholdedImage(IplImage* imgHSV){
    IplImage* imgThresh1 = cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
    cvInRangeS(imgHSV, cvScalar(0,160,40), cvScalar(10,256,256), imgThresh1);
    //cvInRangeS(imgHSV, cv_RGB(155,0,0), cv_RGB(255,130,130), imgThresh1);
    return imgThresh1;
}
void trackObject(IplImage* imgThresh) {
    // Calculate the moments of 'imgThresh'
    CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
    cvMoments(imgThresh, moments, 1);
    double moment10 = cvGetSpatialMoment(moments, 1, 0);
    double moment01 = cvGetSpatialMoment(moments, 0, 1);
    double area = cvGetCentralMoment(moments, 0, 0);
    // if the area<1000, I consider that the there are no object in the image and it's because of the noise, the area is not zero
    if(area>400){
        // calculate the position of the ball
        int posX = moment10/area;
        int posY = moment01/area;
 
        if(lastX>=0 && lastY>=0 && posX>=0 && posY>=0)
        {
            cout << "yes" << endl;
            cout << "posX = " << posX << endl;
            cout << "lastX = " << lastX << endl;
            // Draw a yellow line from the previous point to the current point
            cvLine(imgTracking, cvPoint(posX, posY), cvPoint(lastX, lastY), cvScalar(0,0,255), 4);
        }
 
        lastX = posX;
        lastY = posY;
    }
 
    free(moments);
}