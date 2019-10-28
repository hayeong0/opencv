#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    /*** Addition example ***/
    Mat img1 = imread("lena.png");
    Mat img2 = imread("lena.png");
    Mat dst;
    add(img1, img2, dst);
    imshow("dst", dst);
    waitKey(0);
    return 0;

    /*** Threshold operation ***/
    Mat image = imread("lena.png");
    cvtColor(image, image, CV_BGR2GRAY);
    Mat dst;
    threshold(image, dst, 100, 255, THRESH_BINARY);

    imshow("dst", dst);
    imshow("image", image);
    waitKey(0);
    return 0;

    /*** Threshold operation 2 ***/
    Mat image = imread("lena.png");
    cvtColor(image, image, CV_BGR2GRAY);
    // Mat image = imread("lena.png", IMREAD_GRAYSCALE);
    Mat dst;
    adaptiveThreshold(image, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 10);
    imshow("dst", dst);
    imshow("image", image);
    waitKey(0);
    return 0;

    /*** Threshold operation 2 ***/
    Mat image = imread("hand.png");
    cvtColor(image, image, CV_BGR2YCrCb);
    inRange(image, Scalar(0, 133, 77), Scalar(255, 173, 127), image);

    imshow("in Range", image);
    waitKey(0);
    return 0;
}