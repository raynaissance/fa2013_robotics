#include "Util.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv/highgui.h>
#include <opencv/cv.h>
using namespace std;
int main()
{
  IplImage* map;
  std::vector<CvPoint > edges;
  std::vector<CvPoint > doors;
  std::vector<CvPoint > docks;
  CvPoint arcReactorLoc;
 
  parseFile(edges,doors,docks,arcReactorLoc);
  CvSize ImageSize1 = cvSize(300,300);
  map = cvCreateImage(ImageSize1,IPL_DEPTH_8U,3);
  cvNamedWindow("Map of X Planet",1);
  while(1) {
    map = drawMap(map, edges, doors, docks, arcReactorLoc); 
    cvShowImage("Map of X Planet",map);
    cvWaitKey(100000);  
  }
  return 0;
}