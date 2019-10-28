/* 
2. Perform color slicing on Apple.jpg.
Display regions whose color is not red as gray
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image = imread("apple.jpg");
    Mat HSV, mask_out; 
    vector<Mat> channel(3);

    int rows = image.rows; 
    int cols = image.cols; 

    uchar* h;
    uchar* s;
    uchar* v;

    cvtColor(image, HSV, CV_BGR2HSV); 
    split(HSV, channel);

    // regions of apple --> red
    for (int i = 0; i < rows; i++) {
        h = channel[0].ptr<uchar>(i);
        s = channel[1].ptr<uchar>(i);
    for (int j = 0; j < cols; j++) {
        if (h[j] >= 0  && h[j] <= 20) s[j] = s[j];
        else if (h[j] >= 140  && h[j] <= 179) s[j] = s[j];
        else s[j] = 0; 
        }    
    }
    
    merge(channel, mask_out);
    cvtColor(mask_out, mask_out, CV_HSV2BGR); 

    imshow("image", image);
    imshow("apple", mask_out); 

    waitKey(0);
    return 0; 
}

int main()
{
	Mat apple = imread("Apple.jpg");
	Mat apple_hsv, merged, result;
	vector<Mat> HSV;

	cvtColor(apple, apple_hsv, CV_BGR2HSV);
	split(apple_hsv, HSV);

	for (int i = 0; i < apple_hsv.rows; i++)
	{
		for (int j = 0; j < apple_hsv.cols; j++)
		{
			if ((15 < HSV[0].at<uchar>(i, j)) && HSV[0].at<uchar>(i, j) < 165)
			{
				HSV[1].at<uchar>(i, j) = 0;
			}
		}
	}

	merge(HSV, merged);
	cvtColor(merged, result, CV_HSV2BGR);

	imshow("result", result);
	waitKey(0);
	return 0;
}
