#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("apple.jpg");
    Mat dst;
    cvtColor(image, image, CV_BGR2YCrCb);
    inRange(image, Scalar(0, 160, 60), Scalar(255, 255, 140), dst);
    //inRange(image, Scalar(0, 157, 0), Scalar(255, 255, 200), dst);

    imshow("Apple", image);
    imshow("in Range", dst);
    waitKey(0);
    return 0;
}

