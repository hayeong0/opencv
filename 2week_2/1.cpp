/*
1. Display Saturation channel of Lena.png
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image, image_HSV;
    Mat HSV_channels[3];

    image = imread("lena.png");

    cvtColor(image, image_HSV, CV_BGR2HSV);
    split(image_HSV, HSV_channels);

    imshow("Original image", image);
    imshow("Saturation image", HSV_channels[1]);
    imshow("H image", HSV_channels[0]);
    imshow("I image", HSV_channels[2]);
    
    waitKey();
}

   