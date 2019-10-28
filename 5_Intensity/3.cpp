/*
3. Apply gamma correction on reverse_light_1.jpg
- read the file as a gray-scale image
- Generate an image by add 50 to each pixel
- Also generate an image by performing gamma correction
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	Mat image_add = imread("reverse_light_1.jpg", 0);
	Mat image_gamma = imread("reverse_light_1.jpg", 0);
	float gamma = 0.6;
	unsigned char pix[256];
	MatIterator_<uchar> it, end;
	imshow("Original_image", image_add);

	//add50
	for (it = image_add.begin<uchar>(), end = image_add.end<uchar>(); it != end; it++)
	{
		*it = saturate_cast<uchar>(*it + 50);
	}

	//gamma correction
	for (int i = 0; i < 256; i++){
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}
	for (it = image_gamma.begin<uchar>(), end = image_gamma.end<uchar>(); it != end; it++){
		*it = pix[(*it)];
	}

	imshow("add50", image_add);
	imshow("gamma", image_gamma);
	waitKey(0);

	return 0;
}