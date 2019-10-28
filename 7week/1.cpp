/*
1. Perform gamma correction on lena.png.
- Read the image as a color image
- set the value of gamma as 0.5
- Apply gamma correction on intensity channel only
- Apply gamma correction on R, G, B channel
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){

	Mat image=imread("lena.png");
	Mat img_ycrcb, merged;
	vector<Mat> YCrCb_channels;
	MatIterator_<uchar> it, end;

	float gamma = 0.5;
	unsigned char pix[256];

	for (int i = 0; i < 256; i++){
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}

	//image --> ycrcb
	cvtColor(image, img_ycrcb, CV_BGR2YCrCb);
	split(img_ycrcb, YCrCb_channels);
	
	for (it = YCrCb_channels[0].begin<uchar>(), end = YCrCb_channels[0].end<uchar>(); it != end; it++)
	{
		*it = pix[(*it)];
	}

	merge(YCrCb_channels, merged);
	cvtColor(merged, merged, CV_YCrCb2BGR);

	imshow("Input image", image);
	imshow("Gamma_HSV_V", merged);

	Mat merged_BGR;
	vector<Mat> BGR_channels;
	split(image, BGR_channels);

	for (it = BGR_channels[0].begin<uchar>(), end = BGR_channels[0].end<uchar>(); it != end; it++) {
		*it = pix[(*it)]; }
	for (it = BGR_channels[1].begin<uchar>(), end = BGR_channels[1].end<uchar>(); it != end; it++) {
		*it = pix[(*it)]; }
	for (it = BGR_channels[2].begin<uchar>(), end = BGR_channels[2].end<uchar>(); it != end; it++) {
		*it = pix[(*it)]; }

	merge(BGR_channels, merged_BGR);

	imshow("Gamma_BGR", merged_BGR);

	waitKey(0);
	return 0;
}