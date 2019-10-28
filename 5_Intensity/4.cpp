/*
4. Find dout the sentence hidden in dark.jpg and bright.jpg
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    
	Mat image_dark = imread("dark.jpg", 0);
	Mat image_bright = imread("bright.jpg", 0);
	Mat gamma_dark, gamma_bright;
	MatIterator_<uchar> it, end;

	imshow("Origin_dark", image_dark);
	imshow("Origin_bright", image_bright);

	//Automatically estimate gamma Value
	float gammaValue_dark = (sum(image_dark)[0] / image_dark.total()) / 10;
	float gammaValue_bright = (sum(image_bright)[0] / image_bright.total()) / 10;
	unsigned char pix[256];

	gamma_dark = image_dark.clone();
	gamma_bright = image_bright.clone();

	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gammaValue_dark) * 255.0f);
	}
	for (it = gamma_dark.begin<uchar>(), end = gamma_dark.end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}

	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gammaValue_bright) * 255.0f);
	}
	for (it = gamma_bright.begin<uchar>(), end = gamma_bright.end<uchar>(); it != end; it++)
	{
		*it = pix[(*it)];
	}

	imshow("Gamma_dark", gamma_dark);
	imshow("Gamma_bright", gamma_bright);
	waitKey(0);
	return 0;
}