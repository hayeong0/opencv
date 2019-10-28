#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){

    Mat gray_image;
    int value, channels;
    
    gray_image = imread("lena.png", 0);
    channels = gray_image.channels();

    value = gray_image.at <uchar>(120, 100);
    
    cout << "value: " << value << endl;

    waitKey(0);
}
