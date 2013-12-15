#ifndef Camera_h
#define Camera_h

#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <opencv2/opencv.hpp>

class Camera
{
  public:
	Camera();
	bool captureImg();
	void standby();
	void turnOff();
	int getObjectX();
	int getObjectY();
	bool initCapture();
  private:
  	CvCapture* capture;
  	IplImage* imgTracking;
    IplImage* frame;
    IplImage* imgHSV;
    IplImage* imgThresh;
    int lastX;
	int lastY;
	int time;
	int status;

	IplImage* GetThresholdedImage(IplImage*);
	void trackObject(IplImage*);

};

#endif

