#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    
	Mat image = imread("lena.png");
	Mat image_dm = image.clone();


	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			if (i % 2 == 0) {
                image.at<Vec3b>(i, j)[0] = 0;
                image.at<Vec3b>(i, j)[1] = 0;
                image.at<Vec3b>(i, j)[2] = 255;
			}
		}
	}
    imshow("image", image);

	waitKey(0);
	return 0;

}