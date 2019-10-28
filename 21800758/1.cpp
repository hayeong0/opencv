#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image, result;
	image = imread("lena.png", 0);
    
	blur(image, result, Size(7, 7));   

	threshold(result, result, 0, 255, THRESH_BINARY | THRESH_OTSU); 

	imshow("Result", result);

	waitKey(0);
	return 0;
}