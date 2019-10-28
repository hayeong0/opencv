/*
1. Perform pixel-based background subtraction on Background.mp4
- Read the video as gray-scale
- set background image as the average of current 10 frames
- Generate a binary image by using the following equation
- Draw bounding rectangle on each moving object whose 
- size is bigger than 200 pixels
- print out the number of moving objects on the image 
    whose size is bigger than 200 pixels.
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap("background.mp4");
	Mat image, sub, result;
	double fps = cap.get(CV_CAP_PROP_FPS);
	vector<Mat> Background_Queue; 
	//Queue : First In First Out (√÷Ω≈ 10∞≥ ¿Ø¡ˆ)

	while(1){
		vector<vector<Point>> contours;
		vector<Vec4i>hierarchy;

		cap >> image;
		result = image.clone(); //deep copy
		if (image.empty()) return -1;

		Mat background = Mat::zeros(image.rows, image.cols, CV_8UC1); // return Inverse matrix
		cvtColor(image, image, CV_BGR2GRAY);	//convert gray scale image

		if (Background_Queue.size() < 10){
			//Background_Queue.begin()에 image 삽입
			Background_Queue.insert(Background_Queue.begin(), image);
		}
		else{
			//Background_Queue의 마지막 원소 제거
			Background_Queue.pop_back();                                      //eliminate oldest
			Background_Queue.insert(Background_Queue.begin(), image);         //add new
		}

		//As a result, it will be a mean of 10 frame
		for (int i = 0; i < Background_Queue.size(); i++){
			add(Background_Queue[i] / (i + 1.0), (background * i) / (i + 1.0), background);     	
		}
		
		//absdiff - 두 프레임 사이에 다른 부분 절댓값 계산
		//background - image의 절댓값 sub
		absdiff(background, image, sub);

		//generate a binary image
		threshold(sub, sub, 20, 255, THRESH_BINARY);

		//counting num of contour
		findContours(sub, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

		vector<Rect> boundRect(contours.size());
		int rect_num = 0;

		//draw bounding rectangle on each moving object
		for (int i = 0; i < contours.size(); i++){
			//automatically find rectangle boundary Func
			boundRect[i] = boundingRect(contours[i]);                          
			if (boundRect[i].area() > 200){
				rectangle(result, boundRect[i], Scalar(255, 255, 255), 2, 8);
				rect_num++;
			}
		}
		
		putText(result, format("# Rect: %d", rect_num), Point2f(10, 30), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255), 2);
		imshow("result", result);

		waitKey(1000 / fps);
	}
	return 0;
}