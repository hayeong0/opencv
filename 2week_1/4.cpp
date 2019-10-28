#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image(Size(1920, 1080), CV_8UC3, Scalar(0, 255, 255));
  
    imshow("image", image);
    waitKey();
}