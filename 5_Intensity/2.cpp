/* 
2. perform gamma correction on Aerial_image.png
and Fracture_spline.png
- read the file as a greay-scale image
- check the result when you change the gamma value
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat Aerial = imread("Aerial_image.png", 0);
	Mat Fracture = imread("Fracture_spline.png", 0);
	Mat gamma_Aerial, gamma_Fracture;

	imshow("Aerial", Aerial);
	imshow("Fracture", Fracture);
	
	MatIterator_<uchar> it, end;
    //어둡게 하고 싶으면 감마값을 1보다 크게
    //밝게 하고 싶으면 감마값을 1보다 작게
	float gammaValue_Aerial = 5.0;
	float gammaValue_Fracture = 0.3;
	unsigned char pix[256];

	gamma_Aerial = Aerial.clone();
	gamma_Fracture = Fracture.clone();

    //0-255 사이의 값으로 맞춰줌
	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gammaValue_Aerial) * 255.0f);
	}
    //감마 수행
	for (it = gamma_Aerial.begin<uchar>(), end = gamma_Aerial.end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}

	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gammaValue_Fracture) * 255.0f);
	}
	for (it = gamma_Fracture.begin<uchar>(), end = gamma_Fracture.end<uchar>(); it != end; it++)
	{
		*it = pix[(*it)];
	}

	imshow("Gamma transformation2", gamma_Aerial);
	imshow("Gamma transformation3", gamma_Fracture);
	waitKey(0);
	return 0;
}