/* 
2. compute and print out normalized histograms of
R-channel of Apple.jpg in the following cases
- normalized histogram of the whole image
- normalized histogram of a ROI whose left-top position
and right -bottom position are (x:160, y:140) and (x:340, y:370)
- set the number of bins as 8
*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat drawHistogram(Mat img);

int main() {

	Mat img = imread("apple.jpg");

	Mat rgb_channels[3];
	Mat hist_roi, hist_whole;
	split(img, rgb_channels);

	Rect rect(Point(160, 140), Point(340, 370));
	Mat roi = rgb_channels[2](rect);

	imshow("whole", rgb_channels[2]);
	imshow("roi", roi);

	hist_roi = drawHistogram(roi);
	hist_whole = drawHistogram(rgb_channels[2]);

	imshow("hist_whole", hist_whole);
	imshow("hist_roi", hist_roi);

	waitKey(0);
	return 0;
}

//Drawing histogram function

void drawHistogram(Mat src)
{
	Mat hist;

	//establish the number of bins
	int i, hist_w, bin_w, histSize;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	hist_w = 256;
	histSize = 8;
	bin_w = cvRound((double)hist_w / histSize);

	//compute the histograms
	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange, true, false);

	for (i = 0; i < histSize; i++)
	{
		printf("range(%d ~ %d) : %f\n", bin_w*i, bin_w*i + hist_w / histSize, hist.at<float>(i)/src.total());
	}
	return;
}