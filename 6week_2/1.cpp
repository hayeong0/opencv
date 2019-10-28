/*
1. Apply averaging filtering and median filtering 
on Saltnpepper.png
- read the image as as gray-scale image
- set the mask size as 7*7
*/
#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat image_salt, Avgimg, Medianimg;
	image_salt = imread("saltnpepper.png", 0);

	blur(image_salt, Avgimg, Size(7, 7));        //averaging filtering

	medianBlur(image_salt, Medianimg, 3);        //median filtering

	imshow("average", Avgimg);
	imshow("median", Medianimg);
	waitKey(0);
	return 0;
}