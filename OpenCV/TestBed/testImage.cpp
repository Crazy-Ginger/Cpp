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
    circle(image, Point(350,350), 80, Scalar(255,0, 0), 1, LINE_4);

    circle(image, Point(350,350), 82, Scalar(0,0,255), 1, LINE_8);
    //string text = to_string(i);
    //putText(image, text, Point (100, 100), 20, 1, Scalar(200,200,200)); 
    imshow(winName, image);
    waitKey(0);
    return 0;
}
