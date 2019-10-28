/*
Draw 2 lines on road.mp4.
Two lines shold start 
from the top of the image and end at the bottom of the image
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    
    Mat frame;
    VideoCapture cap("road.mp4");

    while(1){
        cap >> frame;

        Point p1(280, 0), p2(550, 480);
        line(frame, p1, p2, Scalar(255, 0, 0), 3, 8, 0);

        Point p3(280, 480), p4(550, 0);
        line(frame, p3, p4, Scalar(255, 0, 0), 3, 8, 0);

        if(frame.empty()){
            cout << "end of video" << endl;
            break;
        }

        if(!frame.empty()){
            imshow("frame", frame);
            waitKey(33);
        }
    
    }
    return 0;
}

/* 빨간색 엑스자 
    VideoCapture cap("road.mp4");
	Mat frame;

	double fps = cap.get(CAP_PROP_FPS);
	double delay = 1000 / fps;
	int width = cap.get(CAP_PROP_FRAME_WIDTH);
	int height = cap.get(CAP_PROP_FRAME_HEIGHT);

	while (1) {
		cap >> frame;
		if (frame.empty()) break;

		line(frame, Point(0, 0), Point(width, height), Scalar(0, 0, 255), 4, 8, 0);
		line(frame, Point(width, 0), Point(0, height), Scalar(0, 0, 255), 4, 8, 0);

		imshow("frame", frame);
		waitKey(delay);
	}

    */