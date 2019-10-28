#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	// // 컬러 이미지를 저장할 Mat 개체를 생성
	// int width = 500;
	// int height = 500;

    // Mat img = imread("lena.png");
	// //Mat img(height, width, CV_8UC3, Scalar(0, 0, 0));

	// // 선굵기 3인 빨간색 사각형
	// rectangle(img, Point(50, 50), Point(450, 450), Scalar(0, 0, 255), 3);

	// // 내부가 파란색으로 채워진 사각형 
	// rectangle(img, Point(150, 200), Point(250, 300), Scalar(255, 0, 0), -1);


	// imshow("result", img);
	// waitKey(0);


	// return 0;




    Mat img_color = imread("lena.png", IMREAD_COLOR);

	int height = img_color.rows;
	int width = img_color.cols;

	Mat img_grayscale(height, width, CV_8UC1);


	for (int y = 0; y < height; y++) {
		uchar* pointer_input = img_color.ptr<uchar>(y);
		uchar* pointer_ouput = img_grayscale.ptr<uchar>(y);
		for (int x = 0; x < width; x++) {
            // 컬러영상의 경우 픽셀값 읽어오기
			uchar b = pointer_input[x * 3 + 0];
			uchar g = pointer_input[x * 3 + 1];
			uchar r = pointer_input[x * 3 + 2];
            //그레이스케일의 경우 픽셀값 저장하기
			pointer_ouput[x] = (r + g + b) / 3.0;
		}
	}

	imshow("color", img_color);
	imshow("grayscale", img_grayscale);

	waitKey(0);


	return 0;
}


