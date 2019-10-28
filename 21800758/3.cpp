/*
3,
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image, sub;
	VideoCapture cap("background.mp4");
    Mat element = getStructuringElement(MORPH_CROSS, Size(5, 5));
	double fps = cap.get(CV_CAP_PROP_FPS);
	vector<Mat> Background_Queue; 

	while(1){
		cap >> image;
		if (image.empty()) return -1;

		Mat background = Mat::zeros(image.rows, image.cols, CV_8UC1); 
		cvtColor(image, image, CV_BGR2GRAY);	

        // 최초 10개의 프레임 사용
		if (Background_Queue.size() < 10){
			//Background_Queue.begin()에 image 삽입
			Background_Queue.insert(Background_Queue.begin(), image);
		}
		// 평균 구하기
		for (int i = 0; i < Background_Queue.size(); i++){
			add(Background_Queue[i] / (i + 1.0), (background * i) / (i + 1.0), background);     	
		}
		
		absdiff(background, image, sub);
		threshold(sub, sub, 40, 255, THRESH_BINARY);
		morphologyEx(sub, sub, MORPH_CLOSE, element);
	
		imshow("result", sub);

		waitKey(1000 / fps);
	}
	return 0;
}