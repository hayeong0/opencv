#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    /* Rectangle */
    Mat image = imread("lena.png");
    Rect rect = Rect(10, 10, 100, 100);
    //rect크기의 사각형 생성, blue로 칠함
    rectangle(image, rect, Scalar(255, 0, 0), 4, 8, 0);
    imshow("image", image);
    waitKey(0);
    return 0;
    
    /*line*/
    Mat image = imread("lena.png");
    Point p1(25, 25), p2(100, 50);
    line(image, p1, p2, Scalar(255, 0, 0), 3, 8, 0);
    imshow("image", image);
    waitKey(0);
    return 0;

    /*polygon*/
    Mat image = Mat::zeros(400, 400, CV_8UC3);
    int w = 400;
    
    Point trapezoid[1][4];
    trapezoid[0][0] = Point(w*2/6, w/4);
    trapezoid[0][1] = Point(w*4/6, w/4);
    trapezoid[0][2] = Point(w*5/6, w*3/4);
    trapezoid[0][3] = Point(w/6, w*3/4);

    const Point* ppt[1] = {trapezoid[0]};
    int npt[] = {4};

    fillPoly(image, ppt, npt, 1, Scalar(255, 255, 255), 8);
    imshow("image", image);
    waitKey(0);

    /* write text */
    Mat image = Mat::zeros(400, 600, CV_8UC3);
    int w = image.cols; 
    int h = image.rows; 
    putText(image, format("width : %d, height : %d", w, h),
    Point(50, 80), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 200, 200), 4);
    imshow("image", image);

    waitKey(0);
    return 0;

    /* copy */
    Mat m1 = (Mat_ < double > (3,3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
    Mat m_shallow = m1;
    Mat m_deep = m1.clone();

    cout << "m1 = \n" << m1 << endl << endl;
    cout << "m_shallow = \n" << m_shallow << endl << endl;
    cout << "m_deep = \n" << m_deep << endl << endl;

    //update m1
    m1.at < double > (0,0) = 100;
    cout << "m1 = \n" << m1 << endl << endl;
    cout << "m_shallow = \n" << m_shallow << endl << endl;
    cout << "m_deep = \n" << m_deep << endl << endl;

    waitKey(0);

    Mat image, image_gray;
    int value, value_B, value_G, value_R, channels;

    image = imread("lena.png");
    image_gray = imread("lena.png", 0);
    //channels = image.channels();
    channels = image_gray.channels();

    switch(channels){
        case 1:
        value = image.at <uchar>(50, 100);
        cout << "value: " << value;
        break;

        case 3:
        value_B = image.at<Vec3b>(50, 100)[0];
        value_G = image.at<Vec3b>(50, 100)[1];
        value_R = image.at<Vec3b>(50, 100)[2];
        cout << "value at (100, 50): " << value_B << " " << value_G <<
        " " << value_R << endl;
        break;
    }
    waitKey(0);

    


    int main() {
        Mat image = imread("lena.png");
        int value, value_B, value_G, value_R, channels;
        channels = image.channels();

        //Pointer
        uchar* p;
        p = image.ptr<uchar>(50);
        value_B = p[100 * channels + 0];
        value_G = p[100 * channels + 1];
        value_R = p[100 * channels + 2];

        cout << "value at (100,50): " << value_B << " "
        << value_G << " " << value_R << endl;

        waitKey(0);
    }
}



int main() {
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
value_B = (*it3)[0];
value_G = (*it3)[1];
value_R = (*it3)[2];
cout << "B: " << value_B << ", G: " << value_G << ", R: " << value_R << endl;
}
break;
}
waitKey(0);
}