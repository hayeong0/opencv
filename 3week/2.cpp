#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat img1 = imread("apple.jpg");
    Mat img2 = imread("Fracture_spine.png");
    Mat result_add;

    add(img1, img2, result_add);

    imshow("add", result_add);

    waitKey(0);
    return 0;
}