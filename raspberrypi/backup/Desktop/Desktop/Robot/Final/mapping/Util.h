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
void parseFile(
               std::vector<CvPoint> &edges,
               std::vector<CvPoint> &rocket,
               std::vector<CvPoint> &dock,
               CvPoint &arcReactorLoc
               ) {
    std::ifstream myfile;
    myfile.open ("map.txt");
    if (myfile.is_open()){
        while (!myfile.eof()){
            CvPoint p1;
            CvPoint p2;
            int type;// 0 is wall,1 is rocket, 2 is docking
            if (myfile >> p1.x >> p1.y >> p2.x >> p2.y >> type != NULL){
                p1.x = p1.x*25;//convert ft to cm
                p1.y = p1.y*25;//convert ft to cm
                p2.x = p2.x*25;//convert ft to cm
                p2.y = p2.y*25;//convert ft to cm
                if(type == 0) {
                    edges.push_back(p1);
                    edges.push_back(p2);
                }
 else if(type == 1){
                    //Do door
                    rocket.push_back(p1);
                    rocket.push_back(p2);
                }
 else if(type ==2){
                    //Docking station format is X Y W H
                    // p1 is center of docking station
                    // p2.i is width and p2.j is height
                    dock.push_back(p1);
                    dock.push_back(p2);
 
                }else if(type == 3){
                    arcReactorLoc.x = p1.x;
                    arcReactorLoc.y = p1.y;
 
                }
            }
        }
    }
    myfile.close();
}
IplImage* drawMap(IplImage* img,
    std::vector<CvPoint> &edges,
    std::vector<CvPoint> &rocket,
    std::vector<CvPoint> &docks,
    CvPoint &arcReactorLoc
    ){
    //Draw Wall
    for(int i = 0;i < edges.size()-1; i+=2){
      CvPoint p1 = edges[i];
      CvPoint p2 = edges[i+1];
      cvLine(img,p1,p2,CV_RGB(255,255,255));
    }
    //Draw Rocket Station
    for(int i = 0;i < rocket.size()-1; i+=2) {
      CvPoint p1 = rocket[i];
      CvPoint p2 = rocket[i+1];
 
      CvPoint topLeft1, topRight1, bottomLeft1, bottomRight1;
      topLeft1.x = int (p1.x - p2.x/2);
      topLeft1.y = int (p1.y - p2.y/2);
      topRight1.x = int (p1.x + p2.x/2);
      topRight1.y = int (p1.y - p2.y/2);
      bottomLeft1.x = int (p1.x - p2.x/2);
      bottomLeft1.y = int (p1.y + p2.y/2);
      bottomRight1.x = int (p1.x + p2.x/2);
      bottomRight1.y = int (p1.y + p2.y/2); 
 
      cvLine(img,topLeft1, bottomRight1, CV_RGB(0, 150, 150));
      cvLine(img,topRight1, bottomLeft1, CV_RGB(0, 150, 150));
  }
  //Draw Docking Station
  for(int i = 0;i < docks.size()-1; i+=2){
    CvPoint p1 = docks[i];
    CvPoint p2 = docks[i+1];
 
    CvPoint topLeft, topRight, bottomLeft, bottomRight;
    topLeft.x = int (p1.x - p2.x/2);
    topLeft.y = int (p1.y - p2.y/2);
    topRight.x = int (p1.x + p2.x/2);
    topRight.y = int (p1.y - p2.y/2);
    bottomLeft.x = int (p1.x - p2.x/2);
    bottomLeft.y = int (p1.y + p2.y/2);
    bottomRight.x = int (p1.x + p2.x/2);
    bottomRight.y = int (p1.y + p2.y/2); 
    cvRectangle(img, topLeft, bottomRight, cvScalar(204, 0, 204, 0),1,8,0);
 
    cvLine(img,topLeft, bottomRight, CV_RGB(204,0,204));
    cvLine(img,topRight, bottomLeft, CV_RGB(204,0,204));
  }
    //Draw Arc Reactor Location
    cvCircle(img, arcReactorLoc, 10, CV_RGB(255,0,0), 5, CV_AA, 0);
    return img;
}