#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    Mat image = imread("lena.png");
    Mat gray = imread("lena.png", 0);
    int value, value_B, value_G, value_R;
    // try both image & gray
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
            (*it3)[0] = 255;
            value_G = (*it3)[1];
            value_R = (*it3)[2];
        }
        break;
    }

    imshow("image", image);
    waitKey(0);
}


// Mat image = imread("lena.png");

// 	MatIterator_<Vec3b> it, end;

// 	for (it = image.begin<Vec3b>(), end = image.end<Vec3b>(); it != end; ++it)
// 		(*it)[0] = 255;

// 	imshow("image", image);
// 	waitKey();