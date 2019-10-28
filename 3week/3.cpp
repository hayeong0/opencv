#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image_color, image_gray;
	image_color = imread("lena.png");

	cvtColor(image_color, image_gray, CV_BGR2GRAY);

	threshold(image_gray, image_gray, 128, 200, CV_THRESH_BINARY);
	threshold(image_color, image_color, 128, 200, CV_THRESH_BINARY);

	imshow("image_gray", image_gray);
	imshow("image_color", image_color);

    waitKey(0);
    return 0;
}



// 1. 0~5초 재생 x, 5~10 재생
// 2. 50번째 열부터, 100번째 열까지 빨간색
// 동영상의 width의 height --> 노란색 (text, 시작 위치 ,200, 100)
// 영상의 원점이 left-top임

// apple.jpg 
// 큰 사과만 추출  ROI 영역에 대해서 사과 추출 (바이너리 값) (파란색 테두리), 영상 하단 부분 --> 흑백 영상처럼 보이게))