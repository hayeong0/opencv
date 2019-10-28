/*1번 */
// #include <iostream>
// #include <opencv2/opencv.hpp>

// using namespace std;
// using namespace cv;

// int main() {
// 	VideoCapture cap("background.mp4");
// 	Mat frame;

// 	double fps = cap.get(CAP_PROP_FPS);
// 	double delay = 1000 / fps;

// 	while (1) {
// 		cap >> frame;
// 		if (frame.empty())
// 			break;

// 		imshow("background", frame);
// 		waitKey(delay);
// 	}
// }
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap_f("background.mp4");
	VideoCapture cap_s("background.mp4");
	Mat faster, slower;

	double fps = cap_f.get(CAP_PROP_FPS);
	double delay = 1000 / fps;
	int count = 0;

	while (1) {
		cap_f >> faster;
		if (count % 2 == 0)
			cap_s >> slower;

		if (faster.empty() || slower.empty())
			break;

		imshow("faster", faster);
		imshow("slower", slower);
		waitKey(delay);

		count++;
	}
}

