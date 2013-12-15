#ifndef Vision_h
#define Vision_h

#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <opencv2/opencv.hpp>
#include "Camera.h"

class Vision
{
  public:
	Vision(int argc, char* argv[]);
	void captureImg();
	void start();
	void stop();
	void send();
	void receive();
  private:
  	int fd;
	char buffer[10];
	Camera cam;

	int redObjectX;
	int redObjectY;
};

#endif

