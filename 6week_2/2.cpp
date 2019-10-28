/*
2. Perform sharpening by unsharp masking on Moon.png
- read the image as a gray-scale image
- set the weight for unsharp mask as 0.5
*/
#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image, laplacian, sharpening;
	image = imread("new_moon.jpg", 0);
	imshow("Input image", image);

	//Sharp_Second_Derivative
	GaussianBlur(image, image, Size(3, 3), 0);

    //Laplacian 함수를 사용하여 영상의 이차미분 값을 구한다. 
    //이 때 이차미분 값은 음수가 나올수도 있으므로 OutArray의 type은 
    //U(unsigned)가 아닌 S(signed) --> (CV_16S)
	Laplacian(image, laplacian, CV_16S);

    // +, - 연산자는 피연산자의 매트릭스 타입이 일치해야함
    // 원본 image도 16bit Signed로 변경
	image.convertTo(image, CV_16S);
    // 픽셀 값 차이를 분명하게 하기 위해, 2차 미분값을 빼주어야 함
	sharpening = image - laplacian;
    // imshow를 위해 다시 CV_8U로 변경
	sharpening.convertTo(sharpening, CV_8U);

	imshow("Sharp_Second", sharpening);

	waitKey(0);

	return 0;
}