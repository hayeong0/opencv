#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat frameF;
    Mat frameS;
    VideoCapture cap1("background.mp4");
    VideoCapture cap2("background.mp4");

    while(1){
        cap1 >> frameF;
        cap2 >> frameS;

        if(frameF.empty() || frameS.empty()){
            cout << "end of video" << endl;
            break;
        }
        
        if(!frameF.empty()){
            imshow("faster ver", frameF);
            waitKey(33);
        }

        cap1 >> frameF;
        if(!frameF.empty()){
            imshow("faster ver", frameF);
            waitKey(33);
        }

        if(!frameS.empty()){
            imshow("slow ver", frameS);
            waitKey(33);
        }
    }
}

/*
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
}*/