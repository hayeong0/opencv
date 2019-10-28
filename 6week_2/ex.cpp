#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image, laplacian, abs_laplacian, sharpening;
    //이미지 불러오기
    image = imread("Moon.png", 0);
    //Gaussian Blur 수행 (noise 제거)
    GaussianBlur(image, image, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // calculates the Laplacian of an image
    // image: src, laplacian: dst, CV_16S: desire depth of dst,
    // 1: aperture size used to compute second-derivative (optional)
    // 1: optional scale factor for the computed Laplacian values
    // 0: optional delta value that is added to the result
    //Laplacian 연산 수행 (2차 미분)
    // image(원본), laplacian(결과) CV_16S (16bit short/ 수행했을때 값의 범위, mask 크기, 특정한 scale 곱할 떄, 특정한 scale 더할때)
    Laplacian(image, laplacian, CV_16S, 1, 1, 0);
    //8bit 영상으로 바꾼다
    // convertScaleAbs(laplacian, abs_laplacian);
    //연산된 이미지를 더한다
    sharpening = abs_laplacian + image;

    imshow("Input image", image);
    imshow("Laplacian", laplacian);
    imshow("abs_Laplacian", abs_laplacian);
    imshow("Sharpening", sharpening);

    waitKey(0);
}