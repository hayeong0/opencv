#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat img1 = imread("apple.jpg");
    Mat img2 = imread("lena.png");
    Mat result_sub;
    Mat result_absd;

    subtract(img1, img2, result_sub);
    absdiff(img1, img2, result_absd);

    imshow("subtraction", result_sub);
    imshow("absdiff", result_absd);

    waitKey(0);
    return 0;
}