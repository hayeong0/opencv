#include "cv.hpp"
#include <iostream>
#include "ml.hpp"

using namespace cv;
using namespace std;
using namespace cv::ml;

// Exercise 1
// 1-1
#if 0
int main() {
	Mat originalFrame, yCbCrFrame;
	VideoCapture cap;
	double fps;
	int totalFrames, currFrame;
	vector<Mat> yCbCr_channels(3);
	string text;

	if (cap.open("assets/pedestrian.avi") == 0) {
		cout << "so such file" << endl;
		waitKey(0);
		return -1;
	}
	fps = cap.get(CAP_PROP_FPS);
	totalFrames = cap.get(CAP_PROP_FRAME_COUNT);

	while (1) {
		if (cap.grab() == 0) break;
		cap.retrieve(originalFrame);
		currFrame = cap.get(CAP_PROP_POS_FRAMES);

		cvtColor(originalFrame, yCbCrFrame, CV_RGB2YCrCb);
		split(yCbCrFrame, yCbCr_channels);

		putText(yCbCr_channels[1], format("%d/%d", currFrame, totalFrames),
			Point(25, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0), 3);

		imshow("Cr", yCbCr_channels[1]);

		waitKey(1000 / fps);
	}
	return 0;
}
#endif

// 1-2
#if 0
int main() {
	Mat image = imread("assets/lena.png");
	int zero_count = 0;

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			if (i % 4 == 0) {
				image.at<Vec3b>(i, j) = (0, 0, 0);
			}
		}
	}

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			if (image.at<Vec3b>(i, j) == Vec3b(0, 0, 0))
				zero_count++;
		}
	}

	cout << "zero pixel count: " << zero_count << endl;
	imshow("image", image);
	waitKey(0);
	return 0;
}
#endif

// 1-3
#if 0
int main() {
	Mat image = imread("assets/hand.jpg", 0);
	Rect rect(0, 0, image.size().width, image.size().height / 2);
	threshold(image(rect), image(rect), 128, 255, THRESH_BINARY_INV);
	resize(image, image, Size(600, 600));
	imshow("image", image);
	waitKey(0);
	return 0;
}
#endif	



// Exercise 2
// 2-1
#if 0
int main() {
	Mat image = imread("lena.png", 0);
	Mat gamma_img = image.clone();;
	MatIterator_<uchar> it, end;
	float gamma = 0.5;
	unsigned char pix[256];

	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}

	for (it = gamma_img.begin<uchar>(), end = gamma_img.end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}
	imshow("Gamma transformation", gamma_img);

	waitKey(0);
	return 0;
}
#endif	

// 2-2
#if 0
Mat drawHistogram(Mat src) {
	Mat hist, histImage;

	//establish the number of bins
	int i, hist_w, hist_h, bin_w, histSize;
	float range[] = { 0, 256 };
	const float* histRange = { range };

	hist_w = 512;
	hist_h = 400;
	histSize = 8;
	bin_w = cvRound((double)hist_w / histSize);

	//compute the thistograms
	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange, true, false);

	//draw the histogram
	histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	//normalize the result to [0, histImage.rows]
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (i = 0; i < histSize; i++) {
		rectangle(histImage, Point(bin_w*i, hist_h), Point(bin_w*(i + 1), hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), -1, 8, 0);
	}
	return histImage;
}

int main() {
	Mat image;
	Mat hist_graph;

	image = imread("assets/moon.jpg", 0);
	if (!image.data) exit(1); //Check image


	hist_graph = drawHistogram(image);

	imshow("Input Image", image);
	imshow("Hist Graph", hist_graph);

	waitKey(0);
	return 0;
}
#endif

// 2-3
#if 0
int main() {
	Mat AvgImg, laplacian, abs_laplacian, sharpening, g_blur, medImg;
	Mat image = imread("assets/saltnpepper.png", 0);


	//averaging filter ���
	blur(image, AvgImg, Size(7, 7));

	//sharpening using second derivative
	GaussianBlur(image, g_blur, Size(3, 3), 0, 0, BORDER_DEFAULT);
	Laplacian(g_blur, laplacian, CV_16S, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(laplacian, abs_laplacian);
	sharpening = abs_laplacian + g_blur;

	//median filter
	medianBlur(image, medImg, 7);


	imshow("image", image);
	imshow("Average filtering 7x7", AvgImg);
	imshow("Sharpening", sharpening);
	imshow("Median filtering 7", medImg);

	waitKey(0);
	return 0;
}
#endif	


// Exercise 3
// 3-1
#if 0
void watershed() {
	Mat image, gray, binary, erosion, dilation, markers, result;
	Mat mask = getStructuringElement(MORPH_RECT, Size(5, 5));
	image = imread("assets/traffic_light.jpg");
	Mat foreground = Mat(image.size(), CV_8UC3, Scalar(255, 255, 255));
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;


	cvtColor(image, gray, CV_BGR2GRAY);
	threshold(gray, binary, 138, 255, THRESH_BINARY);

	dilate(binary, dilation, mask, Point(-1, -1), 2);
	erode(binary, erosion, mask, Point(-1, -1), 2);
	threshold(dilation, dilation, 1, 128, THRESH_BINARY_INV);

	markers = Mat(binary.size(), CV_8U, Scalar(0));
	markers = erosion + dilation;
	// Create markers image
	//imshow("markers1", markers);

	markers.convertTo(markers, CV_32S);
	watershed(image, markers);

	// Create watershed segmentation object
	markers.convertTo(result, CV_8U);
	//imshow("result", result);

	threshold(result, result, 128, 255, THRESH_BINARY_INV);

	image.copyTo(foreground, result);

	imshow("watershed", foreground);
}

void gmm() {
	Vec3b colorTab[] = {
		Vec3b(0, 0, 0),
		Vec3b(255, 255, 255),
		Vec3b(255, 0, 0),
		Vec3b(0, 255, 255),
		Vec3b(255, 0, 255),
		Vec3b(255, 255, 0),
	};

	Mat data, labels;
	Mat image = imread("assets/traffic_light.jpg");
	Mat result = image.clone();
	Mat foreground = Mat(image.size(), CV_8UC3, Scalar(255, 255, 255));


	//get every pixel
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			Vec3b point = image.at<Vec3b>(i, j);
			Mat tmp = (Mat_<float>(1, 3) << point[0], point[1], point[2]);
			data.push_back(tmp);
		}
	}

	int N = 2; 	//number of segment

	//make and train EM(expectation maximization)
	Ptr<EM> em_model = EM::create();
	em_model->setClustersNumber(N);
	em_model->setCovarianceMatrixType(EM::COV_MAT_SPHERICAL);
	em_model->setTermCriteria(TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 300, 0.1));
	em_model->trainEM(data, noArray(), labels, noArray());

	int n = 0;

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			int clusterIdx = labels.at<int>(n);
			result.at<Vec3b>(i, j) = colorTab[clusterIdx];
			n++;
		}
	}
	image.copyTo(foreground, result);
	imshow("gmm", foreground);
}

void grabcut() {
	Mat result, bgModel, fgModel, image, foreground;

	image = imread("assets/traffic_light.jpg");
	Rect rectangle(65, 0, 170, 230); //inner rectangle which includes foreground

	grabCut(image, result, rectangle, bgModel, fgModel, 10, GC_INIT_WITH_RECT);
	//imshow("bgModel", bgModel);
	//imshow("fgModel", fgModel);
	compare(result, GC_PR_FGD, result, CMP_EQ);
	foreground = Mat(image.size(), CV_8UC3, Scalar(255, 255, 255));

	image.copyTo(foreground, result);
	//imshow("original", image);
	//imshow("Result", result);
	imshow("grabcut", foreground);
}

int main() {
	watershed();
	gmm();
	grabcut();

	waitKey(0);
	return 0;
}
#endif

// 3-2
#if 0
int main() {
	Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2();
	Mat image, foregroundMask, backgroundImg, foregroundImg;
	VideoCapture cap("assets/background.mp4");
	Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3));
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	while (true) {
		cap >> image;
		resize(image, image, Size(640, 480));
		if (foregroundMask.empty())
			foregroundMask.create(image.size(), image.type());

		bg_model->apply(image, foregroundMask, true ? -1 : 0);
		GaussianBlur(foregroundMask, foregroundMask, Size(11, 11), 3.5, 3.5);
		threshold(foregroundMask, foregroundMask, 10, 255, THRESH_BINARY);
		foregroundImg = Scalar::all(0);
		image.copyTo(foregroundImg, foregroundMask);
		bg_model->getBackgroundImage(backgroundImg);

		//implementing opening
		erode(foregroundMask, foregroundMask, element);
		dilate(foregroundMask, foregroundMask, element);

		//finding contous
		findContours(foregroundMask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
		vector<Rect> boundRect(contours.size());
		for (int i = 0; i < contours.size(); i++) {
			boundRect[i] = boundingRect(Mat(contours[i]));
		}

		//draw rectangles on the contours
		for (int i = 0; i < contours.size(); i++) {
			rectangle(foregroundImg, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 255), 2, 8, 0);
		}

		//imshow("foreground mask", foregroundMask);
		imshow("foreground image", foregroundImg);

		//if (!backgroundImg.empty()) {
		//	imshow("mean background image", backgroundImg);
		//}
		waitKey(33);
	}
}
#endif