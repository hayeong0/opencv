
#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void drawHistogram(Mat src){
	Mat hist, histImage;

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

int main() {
    Mat image = imread("balancing.jpg");
    Mat hist_graph;
    
    if (!image.data) exit(1); //Check image

    Mat img_ycrcb, merged;
	vector<Mat> YCrCb_channels;

    cvtColor(image, img_ycrcb, CV_BGR2YCrCb);
	split(img_ycrcb, YCrCb_channels);
	
    //histogram equlization
    equalizeHist(YCrCb_channels[0], merged); 
    
    merge(YCrCb_channels, merged);
	cvtColor(merged, merged, CV_YCrCb2BGR);

    Mat rgb_channels[3];
	split(merged, rgb_channels);

    drawHistogram(rgb_channels[2]); 
   
    imshow("Hist Equalized Image", merged); 

    waitKey(0);
    return 0;
}

