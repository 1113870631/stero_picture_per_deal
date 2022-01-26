#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(void)
{
    Mat tmp = imread("../1.jpg");
    imshow("win",tmp);
    waitKey(0);

    return 0;

}