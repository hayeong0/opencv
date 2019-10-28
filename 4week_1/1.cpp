/* 
1. Draw a green rectangle on the face of "lena" in lena.png
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("lena.png");

    Rect rect = Rect(200, 200, 180, 180);
    rectangle(image, rect, Scalar(0, 255, 0), 4, 8, 0);
    
    imshow("lena", image);
    waitKey(0);
    return 0;
}
