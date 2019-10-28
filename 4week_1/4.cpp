/* 
Display NTH3.mp4 with the information of current frame and total frame.
- the foramt should be "# of current frame / # of total frame
- Text color should be red
- The location of text should start (50, 50)
*/
#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    
    Mat frame;
    VideoCapture cap("NTH3.mp4");

    double fps = cap.get(CAP_PROP_FPS);
	double delay = 1000 / fps;

    while(1){
        cap >> frame;
        if(frame.empty()) break;
    
        putText(frame, format("%.f of current frame / %.f of total frame", 
        cap.get(CAP_PROP_POS_FRAMES), cap.get(CAP_PROP_FRAME_COUNT)),
        Point(50, 50), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 255), 2);
      
        imshow("NTH3", frame);
        waitKey(delay);
        
    }
   
    waitKey(0);
    return 0;
   
}