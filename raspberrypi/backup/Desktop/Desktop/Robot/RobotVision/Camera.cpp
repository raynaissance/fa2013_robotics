#include <iostream>
#include <fstream>
#include <sstream>
#include "time.h"
#include "Camera.h"

using namespace std;
using namespace cv;

Camera::Camera() {
    lastX = -1;
    lastY = -1;
    capture = 0;
 
    capture = cvCaptureFromCAM( CV_CAP_ANY );
    if (cvWaitKey(60) != -1) {
        cout << "Input" << endl;
    }

    if( !capture ) {
        fprintf(stderr, "failed to initialize video capture\n");
        status = -1;
    }
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 160 );
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 120 );
 
    frame = 0;
 
    cvNamedWindow("Video");
    cvNamedWindow("Ball");
 
    if ((frame = cvQueryFrame(capture))) {
        cvShowImage("Video", frame);
    }

    if (cvWaitKey(8000) != -1) {
        cout << "Input" << endl;
    }

    imgHSV = 0;
    imgThresh = 0;
    imgTracking = cvCreateImage(cvSize(160, 120),IPL_DEPTH_8U, 3);
    cvZero(imgTracking); //covert the image, 'imgTracking' to black
    time = 0;
}

bool Camera::captureImg() {
    cout << "time = " << time++ << endl;
 
    if ((frame = cvQueryFrame(capture))) {
        cout << "Got it" << endl;
    }
    if (cvWaitKey(100) != -1) {
        cout << "Input" << endl;
        return false;
    }
    frame = cvCloneImage(frame);

    cvSmooth(frame, frame, CV_GAUSSIAN,3,3); //smooth the original image using Gaussian kernel
    imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);

    cvCvtColor(frame, imgHSV, CV_BGR2HSV); //Change the color format from BGR to HSV, Before I used CV_RGB2GRAY which is wrong
    imgThresh = GetThresholdedImage(imgHSV);

    cvSmooth(imgThresh, imgThresh, CV_GAUSSIAN,3,3); //smooth the binary image using Gaussian kernel
    trackObject(imgThresh);

    cvAdd(frame, imgTracking, frame);
    cvShowImage("Video", frame);
    cvShowImage("Ball", imgThresh);
    return true;
}

void Camera::standby() {

}

void Camera::turnOff() {
    cvReleaseImage(&frame);
    cvReleaseImage(&imgHSV);
    cvReleaseImage(&imgThresh);
    cvDestroyAllWindows();
    cvReleaseImage(&imgTracking);
    cvReleaseCapture(&capture);
}

//This function threshold the HSV image and create a binary image
IplImage* Camera::GetThresholdedImage(IplImage* imghsv){
    IplImage* imgThresh1 = cvCreateImage(cvGetSize(imghsv),IPL_DEPTH_8U, 1);
    cvInRangeS(imghsv, cvScalar(0,160,60), cvScalar(20,256,256), imgThresh1);
    return imgThresh1;
}

void Camera::trackObject(IplImage* imgthresh) {
    // Calculate the moments of 'imgThresh'
    CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
    cvMoments(imgthresh, moments, 1);
    double moment10 = cvGetSpatialMoment(moments, 1, 0);
    double moment01 = cvGetSpatialMoment(moments, 0, 1);
    double area = cvGetCentralMoment(moments, 0, 0);
    // if the area<1000, I consider that the there are no object in the image and it's because of the noise, the area is not zero
    if(area>1000){
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

bool Camera::initCapture() {
    if(status == -1){
        return false;
    }
    return true;
}

int Camera::getObjectX() {
    return lastX;
}

int Camera::getObjectY() {
    return lastY;
}