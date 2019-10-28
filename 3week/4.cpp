#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("lena.png", 0);
	Mat dst_3, dst_5, dst_7;

	adaptiveThreshold(image, dst_3, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, 10);
	adaptiveThreshold(image, dst_5, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 10);
	adaptiveThreshold(image, dst_7, 200, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, 10);

	imshow("blockSize: 3", dst_3);
	imshow("blockSize: 5", dst_5);
	imshow("blockSize: 7", dst_7);
    waitKey(0);
    return 0;
}



