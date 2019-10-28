#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){

	Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2();
	Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3));
	Mat image, gray, foregroundMask, result;
	VideoCapture cap("background.mp4");
	int fps = cap.get(CV_CAP_PROP_FPS);

	while(true){
		cap >> image;
		result = image.clone();

		//read the video as gray scale
		cvtColor(image, gray, CV_BGR2GRAY);

		if (foregroundMask.empty()) {
			foregroundMask.create(gray.size(), gray.type());
		}
		
		//background subtraction using MoG2
		bg_model->apply(gray, foregroundMask);
		GaussianBlur(foregroundMask, foregroundMask, Size(11, 11), 3.5, 3.5);
		threshold(foregroundMask, foregroundMask, 10, 255, THRESH_BINARY);

		vector<vector<Point>> contours;
		vector<Vec4i>hierarchy;

		//erosion and opening
		erode(foregroundMask, foregroundMask, element);
		morphologyEx(foregroundMask, foregroundMask, MORPH_OPEN, element);

		findContours(foregroundMask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

		vector<Rect> boundRect(contours.size());

		for (int i = 0; i < contours.size(); i++)
		{
			boundRect[i] = boundingRect(contours[i]);
			rectangle(result, boundRect[i], Scalar(255, 255, 255), 2, 8);
		}

		putText(result, format("# Rect: % d", (int)contours.size()), Point2f(10, 30), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255), 2);
		imshow("result", result);

		waitKey(1000 / fps);
	}
	return 0;
}