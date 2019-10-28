/*
Draw on trapezoid and one hexagon in one image by using
fillpoly funcion only once
- generate an image whose size is VGA and 
initialize the color of each pixel as yellow. 
Set the color of trapezoid and hexagon as black
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    int width = 640;
	int height = 480;

	Mat img(height, width, CV_8UC3, Scalar(0, 255, 255));

    int w = 300;
    
    Point trapezoid[1][4];
    trapezoid[0][0] = Point(w*2/6, w/4);
    trapezoid[0][1] = Point(w*4/6, w/4);
    trapezoid[0][2] = Point(w*5/6, w*3/4);
    trapezoid[0][3] = Point(w/6, w*3/4);

    Point hexagon[1][6];
    hexagon[0][0] = Point(w*6/6, w/4);
    hexagon[0][1] = Point(w*8/6, w/4);
    hexagon[0][2] = Point(w*9/6, w*2/4);
    hexagon[0][3] = Point(w*8/6, w*3/4);
    hexagon[0][4] = Point(w*6/6, w*3/4);
    hexagon[0][5] = Point(w*5/6, w*2/4);
    
    const Point* ppt[2] = {trapezoid[0], hexagon[0]};
    int npt[] = {4, 6};

    fillPoly(img, ppt, npt, 2, Scalar(0, 0, 0), 8);
    imshow("result", img);

	waitKey(0);
	return 0;
}


/*
Mat background(Size(640, 480), CV_8UC3, Scalar(0, 255, 255));

	Point trapezoid[1][4];
	trapezoid[0][0] = Point(100, 100);
	trapezoid[0][1] = Point(120, 100);
	trapezoid[0][2] = Point(140, 200);
	trapezoid[0][3] = Point(80, 200);

	Point hexagon[1][6];
	hexagon[0][0] = Point(400, 200);
	hexagon[0][1] = Point(500, 200);
	hexagon[0][2] = Point(600, 300);
	hexagon[0][3] = Point(500, 400);
	hexagon[0][4] = Point(400, 400);
	hexagon[0][5] = Point(300, 300);


    Point oxtagon[1][8];
    oxtagon[0][0] = Point();
    oxtagon[0][0] = Point()
    oxtagon[0][0] = Point()
    oxtagon[0][0] = Point()
    oxtagon[0][0] = Point()
    oxtagon[0][0] = Point()
    oxtagon[0][0] = Point()
    oxtagon[0][0] = Point()




	const Point* ppt[2] = { trapezoid[0], hexagon[0] };
	int npt[2] = { 4, 6 };

	fillPoly(background, ppt, npt, 2, Scalar(0), 8);

	imshow("background", background);
    */