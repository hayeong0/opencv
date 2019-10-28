/*
2. perform thresholding on adaptive_1.jpg
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image, binary, adaptive_binary; 
    image = imread("adaptive_1.jpg", 0);

    // threshold binary를 했을 경우, 깨끗하지 않으므로 adaptive threshold 사용
    adaptiveThreshold(image, adaptive_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 85, 15);
    
    imshow("Input image", image); 
    imshow("Result", adaptive_binary); 
    
    waitKey(0);
    return 0;
}
