#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

int main()
{
    double rad = 300;
    for (double i = 0; i < 2*1.57; i += 0.02)
    {
        Mat img = Mat::zeros(700, 700, CV_8UC3), grey;
        char windowName[] = "Display Image";
        namedWindow(windowName);
        moveWindow(windowName, 0, 0);

        double height = abs(cos(i)*rad);
        ellipse(img, Point(350,350), Size(rad, height), 0, 0, 360, Scalar(255,255,255), 5, 8);
        imshow(windowName, img);
        waitKey(70);
    }
    return 0;
}
