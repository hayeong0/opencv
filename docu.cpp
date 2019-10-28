#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;


//영상 읽어올 때 - 현재 프레임과 전체 프레임 수를 찍어줌
    Mat frame;
    VideoCapture cap("NTH3.mp4");

    double fps = cap.get(CAP_PROP_FPS);

    while(1){
        cap >> frame;
        if(frame.empty()) break;
        //writing
        putText(frame, format("%.f of current frame / %.f of total frame", 
        cap.get(CAP_PROP_POS_FRAMES), cap.get(CAP_PROP_FRAME_COUNT)),
        Point(50, 50), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 255), 2);
      
        imshow("NTH3", frame);
        waitKey(1000 / fps);
        
    }
    return 0;
    
//채널에 포인터로 엑세스 할 때
    int value, value_B, value_G, value_R, channels; 
    channels = image.channels();
//Pointer
    uchar* p;
    p = image.ptr<uchar>(50); 
    value_B = p[100 * channels + 0]; 
    value_G = p[100 * channels + 1]; 
    value_R = p[100 * channels + 2];

//mat iterator
int main() {
Mat image = imread("lena.png");
 Mat gray = imread("lena.png", 0); 
 int value, value_B, value_G, value_R; // try both image & gray
int channels = image.channels(); 
MatIterator_ <uchar> it, end; 
MatIterator_<Vec3b> it3, end3; 
switch (channels) {
    case 1:
    for (it = image.begin<uchar>(), image.end<uchar>(); it != end; ++it) {
        value = *it;
        cout << "value: " << value << endl; 
    }
    break;

    case 3:
    for (it3 = image.begin<Vec3b>(), end3 = image.end<Vec3b>(); it3 != end3; ++it3) {
        value_B = (*it3)[0];
        value_G = (*it3)[1];
        value_R = (*it3)[2];

        cout << "B: " << value_B << ", G: " << value_G << ", R: " << value_R << endl;
    }
    break; 
}
    waitKey(0); 
}

//네거티브 오퍼레이션
Mat negative_img = image.clone();
    
    for (int j = 0; j < image.rows; j++){
        for (int i = 0; i < image.cols; i++){
            negative_img.at<uchar>(j, i) = 255 - image.at<uchar>(j, i);
        }
}

//이미지 쪼갤때
Mat rgb_channels[3];
	Mat hist_roi, hist_whole;
	split(img, rgb_channels);

//morphological
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



//입력비디오 각각 따로 출력

switch (frame.channels()) {
            case 1:
                cvtColor(frame, frame, CV_GRAY2BGR);
                break;
            case 3:
                vector<Mat> bgr;
                split(frame, bgr);
                cvtColor(bgr[1], frame, CV_GRAY2BGR);
                
                break;
        }