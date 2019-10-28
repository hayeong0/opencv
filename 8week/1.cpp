/*
<<image segmentation>l

1. perform thresholding on Finger_print.png
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image, result;
    image = imread("Finger.png", 0);

    threshold(image, result, 0, 255, THRESH_BINARY_INV | THRESH_OTSU); 

    imshow("Input image", image);
    imshow("result", result);

    waitKey(0);
}

// int main()
// {
// 	Mat image, thresh;
// 	int thresh_T, low_cnt, high_cnt, low_sum, high_sum, th;

// 	thresh_T = 200;
// 	th = 10;
// 	low_cnt = high_cnt = low_sum = high_sum = 0;

// 	image = imread("Finger.png", 0);
// 	cout << "threshold value: " << thresh_T << endl;

// 	//Binary Search
// 	while (1) {
// 		for (int i = 0; i < image.rows; i++) {
// 			for (int j = 0; j < image.cols; j++) {
// 				if (image.at<uchar>(i, j) < thresh_T) {
// 					low_sum += image.at<uchar>(i, j);
// 					low_cnt++;
// 				}
// 				else {
// 					high_sum += image.at<uchar>(i, j);
// 					high_cnt++;
// 				}
// 			}
// 		}

// 		if (abs(thresh_T - (low_sum / low_cnt + high_sum / high_cnt) / 2.0f) < th) break;
// 		else {
// 			thresh_T = (low_sum / low_cnt + high_sum / high_cnt) / 2.0f;
// 			cout << "threshold value: " << thresh_T << endl;
// 			low_cnt = high_cnt = low_sum = high_sum = 0;
// 		}
// 	}

// 	threshold(image, thresh, thresh_T, 255, THRESH_BINARY);

// 	imshow("input image", image);
// 	imshow("thresholding", thresh);
// 	waitKey(0);
// }