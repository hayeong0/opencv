/* 
3. Apply convertScaleAbs to "night.mp4" video.
Set alpha and beta as 5 and 10, respectively. 
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    
    VideoCapture cap("night.mp4");
	Mat frame, after_convertScaleAbs;

	double fps = cap.get(CAP_PROP_FPS);
	double delay = 1000 / fps;

	while (1) {
		cap >> frame;
		if (frame.empty()) break;

		convertScaleAbs(frame, after_convertScaleAbs, 5, 10);

		imshow("after_convertScaleAbs", after_convertScaleAbs);
		waitKey(delay);
	}
    
    return 0;
}