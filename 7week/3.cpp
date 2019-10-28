/* 
3. Perform color balancing on balancing.jpg 
using gray-world assumption.
*/

#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    Mat image = imread("balancing.jpg");
    Mat Balancing;
    vector<Mat> channel(3);
    int b_sum = 0, g_sum = 0, r_sum = 0;
    int b_avg, g_avg, r_avg, b_val, g_val, r_val; 

    int rows = image.rows; 
    int cols = image.cols; 
    int pixel = rows * cols;

    split(image, channel);
    uchar* b;
    uchar* g;
    uchar* r;

    // bgr 순으로 각각 평균 구하기
    for (int i = 0; i < rows; i++) {
        b = channel[0].ptr<uchar>(i);
        g = channel[1].ptr<uchar>(i);
        r = channel[2].ptr<uchar>(i);
        for (int j = 0; j < cols; j++) {
            b_sum += b[j]; 
            g_sum += g[j]; 
            r_sum += r[j];    
        } 
    }
    b_avg = b_sum / pixel; 
    g_avg = g_sum / pixel; 
    r_avg = r_sum / pixel;

    // bgr_avg가 128이어야 한다.
    // -->  채널별 평균값을 곱해준다
    // 가장 밝기 값이 밝은 픽셀은 흰색으로 (255)
    for (int i = 0; i < rows; i++) {
        b = channel[0].ptr<uchar>(i);
        g = channel[1].ptr<uchar>(i);
        r = channel[2].ptr<uchar>(i);
        for (int j = 0; j < cols; j++) {
            b_val = (128 * b[j]) / b_avg; 
            if (b_val > 255) {
                b[j] = 255; 
            }
            else {
                b[j] = b_val; 
            }
            
            g_val = (128 * g[j]) / g_avg; 
            if (g_val > 255) {
                g[j] = 255; 
            }
            else {
                g[j] = g_val; 
            }

            r_val = (128 * r[j]) / r_avg; 
            if (r_val > 255) {
                r[j] = 255; 
            }
            else {
                r[j] = r_val; 
            }
        }
    }

    merge(channel, Balancing);
    
    imshow("Original", image); 
    imshow("Banlancing", Balancing); 

    waitKey(0);
    return 0;
}