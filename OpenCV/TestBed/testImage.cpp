#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

int main()
{
    char winName[] = "image";
    namedWindow(winName);
    moveWindow(winName, 0, 0);

    Mat image = Mat::zeros(700, 700, CV_8UC3);
    circle(image, Point(700,700), 80, Scalar(0,0,255), 1, LINE_4);

    imshow(winName, image);
    waitKey(0);
    return 0;
}
