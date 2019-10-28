/*
3. perform thresholding on adaptive.png
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image, binary, adaptive_binary; 
    image = imread("adaptive.png", 0);

    threshold(image, binary, 150, 255, THRESH_BINARY);
    adaptiveThreshold(image, adaptive_binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 15);
    
    imshow("Input image", image); 
    imshow("binary", binary);
    imshow("Result", adaptive_binary); 

    waitKey(0);
    return 0;
}


// int main()
// {
// 	Mat image;
// 	image = imread("adaptive.png", 0);
// 	Mat adaptive_binary = Mat(image.rows, image.cols, CV_8UC1);

// 	for (int col = 0; col < image.cols; col++)
// 	{
// 		int col_thresh = 0;
// 		for (int row = 0; row < image.rows; row++)
// 		{
// 			col_thresh += image.at<uchar>(row, col);
// 		}

// 		col_thresh /= image.rows;

// 		for (int row = 0; row < image.rows; row++)
// 		{
// 			if (image.at<uchar>(row, col) > col_thresh)
// 			{
// 				image.at<uchar>(row, col) = 255;
// 			}
// 			else
// 				image.at<uchar>(row, col) = 0;
// 		}

// 	}

// 	imshow("input image", image);

// 	waitKey(0);
// 	return 0;

// }