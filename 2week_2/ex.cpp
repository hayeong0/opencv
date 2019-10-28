/*
Example code in ppt
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image, image_YUV, dst;
    Mat yuv_channels[3];

    image = imread("lena.png");
    
    cvtColor(image, image_YUV, CV_BGR2YUV);
    split(image_YUV, yuv_channels);
    merge(yuv_channels, 3, dst);

    imshow("imput image", image);
    imshow("Y", yuv_channels[0]);
    imshow("U", yuv_channels[1]);
    imshow("V", yuv_channels[2]);
    imshow("dst", dst);

    waitKey(0);
    return 0;
}