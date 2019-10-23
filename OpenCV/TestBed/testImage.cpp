#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

void SetBlock(int value, int startW, int startH, int blockW, int blockH, int channel, Mat &img)
{
    for (int w = 0; w < blockW; w++)
    {
        for (int h = 0; h < blockH; h++)
        {
            img.at<Vec3b>(startH+h, startW+w)[channel] = value;
        }
    }
}

int main()
{
    int height = 700, widths = 700; 
    Mat img = Mat::zeros(height, widths, CV_8UC3);

    for (int x = 0; x < img.cols; x++)
    {
        for (int y = 0; y < img.rows; y++)
        {
            for (int k = 0; k < 3; k++)
            {

            }
        }
        char winName[] = "image";
        namedWindow(winName);
        moveWindow(winName, 0, 0);

        imshow(winName, img);
        waitKey(30);
    }

    char winName[] = "image";
    namedWindow(winName);
    moveWindow(winName, 0, 0);

    imshow(winName, img);
    waitKey(0);
    return 1;
}
