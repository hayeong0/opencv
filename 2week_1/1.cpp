/*
Display “Background.mp4” video
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap("background.mp4");
	Mat frame;

    //frame 속도
	double fps = cap.get(CAP_PROP_FPS);
	double delay = 1000 / fps;

	while (1) {
		cap >> frame;
		if (frame.empty())
			break;

		imshow("background", frame);
		waitKey(delay);
	}
}