/* 
2. Find the width, height of Sun.jpg.
Set left-top region as a ROI of the image 
and display both the original image and the ROI*/
/*
- The shape of the ROI is rectangle. and the left-top position of the ROI is rectangle,
and the left-top position of the ROI is (50,50) and the right - bottom position is (400, 200)
- Set the name of window for the ROI as "ROI"
- Set all the pixel value of ROI as (R = 0, G = 255 , B = 255
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("Sun.jpg");
    imshow("original", image);

    Rect rect(50, 50, 350, 150);
    Mat rect_roi = image(rect);
    rect_roi.setTo(Scalar(255, 255, 0));

    imshow("rectROI", rect_roi);
    imshow("original", image);
    
    waitKey(0);
    return 0;
}