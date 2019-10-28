/*
 Display “Lena.png” using openCV as
A color image (set the name of window as “lena_color”)
A gray-scale image (set the name of window as “lena_gray”)
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat gray_image = imread("lena.png", 0);
    Mat color_image = imread("lena.png");

    imshow("lena_gray", gray_image);
    imshow("lena_color", color_image);

    waitKey(0);
    return 0;
}