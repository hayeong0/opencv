/* 
compute and display histogram of Moon.png
- read the image as a gray-scale image
- set the number of bins as 16
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
Mat drawHistogram(Mat src);

int main()
{
	Mat image;
	Mat hist_graph;

	image = imread("moon.png", 0);

	hist_graph = drawHistogram(image);

	imshow("Input Image", image);
	imshow("Hist Graph", hist_graph);

	waitKey(0);
	return 0;
}

Mat drawHistogram(Mat src){
	Mat hist, histImage;

	//establish the number of bins
	int i, hist_w, hist_h, bin_w, histSize;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	hist_w = 512;
	hist_h = 400;
    //bin size
	histSize = 16;
	bin_w = cvRound((double)hist_w / histSize);

	//compute the histograms
	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange, true, false);

	//draw the histogram
	histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	//normalize the result to [0, histImage.rows]
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (i = 0; i < histSize; i++){
		rectangle(histImage, Point(bin_w * i, hist_h), Point(bin_w * i + hist_w / histSize, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), -1, CV_AA, 0);
	}
	return histImage;
}