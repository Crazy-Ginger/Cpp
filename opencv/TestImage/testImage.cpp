#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
using namespace std;
using namespace cv;

int main()
{
    char release;
    Mat image = Mat::zeros(20, 20, CV_8UC3), grey;
    circle(image, Point(10,10), 5, Scalar(0,0,255), FILLED, LINE_8);
    //image = imread("test.png", 1);
    
    char windowName[] = "Display Image";
    namedWindow(windowName, WINDOW_AUTOSIZE);
    moveWindow(windowName, 0, 0);
    imshow("Display Image", image);
    waitKey(0);
    cvtColor(image, grey, COLOR_BGR2GRAY);
    imshow("Display Image", grey);
    waitKey(0);
    blur(grey, grey, Size(3,3));
    Canny(grey, grey, 50, 150, 3);
    imshow("Display Image", grey);
    waitKey(0);
    cvtColor(grey, image, COLOR_GRAY2BGR);
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            if (image.at<int>(i,j) != 0)
            {
                cout << "\033[1;31m1, \033[0m";
            }
            else 
            {
                cout << "0, ";
            }
        }
        cout << endl;
        //cin >> release;
    }

    return 0;
}
