#include <iostream>
#include <string>
#include <cmath>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;


void setBlock(int value, int startW, int startH, int blockW, int blockH, int channel, Mat &img)
{
    for (int w = 0; w < blockW; w++)
    {
        for (int h = 0; h < blockH; h++)
        {
            img.at<Vec3b>(startH+h, startW+w)[channel] = value/2;
        }
    }
}

int getAverage(Mat img, int widths, int height, int blockW, int blockH, int channel)
{
    int total = 0;
    for (int x = 0; x < blockW; x++)
    {
        for (int y =0;y < blockH; y++)
        {
            total += img.at<Vec3b>(height+y, widths+x)[channel];
        }
    }
    int area = blockH * blockW;
    int average = (total / area);
    return average;
}

int getBrightest(Mat img, int widths, int height, int blockW, int blockH, int channel)
{
    int brightest = 0;
    for (int x = 0; x < blockW; x++)
    {
        for (int y =0;y < blockH; y++)
        {

            int current = img.at<Vec3b>(height+y, widths+x)[channel];
            if (current > brightest)
            {
                brightest = current;
            }
        }
    }
    return brightest;
}


int main(int argc, char* argv[])
{
    /*
    argv[0]: program name (e.g. "pixeler")
    argv[1]: the height of pixelating blocks (in pixels)
    argv[2]: the width of pixelating blocks (in pixels) 
    argv[3]: whether the image will use the brightest value or average (1 for bright anything else for average)
    argv[4]: the image to be pixelated
    argv[5] (optional): output file name (will be a png) without this the program just displays the image for the viewer
     */

    if (argc < 5)
    {
        cout << "Error not enought arguments\n";
        return 2;
    }
    int blockH = stoi(argv[1]);
    int blockW = stoi(argv[2]);
    
    Mat img;
    img = imread(argv[4], IMREAD_COLOR);
    
    if (!img.data)
    {
        cout << "Error couldn't read the file\n";
        return 2;
    }

    int height = (img.rows/blockH)*blockH;
    int widths = (img.cols/blockW)*blockW;

    Mat newImg = Mat(height, widths, CV_8UC3, Scalar(0,0,0));

    for(int x = 0; x < widths - blockW; x+= blockW)
    {
        for (int y = 0; y < height - blockH; y+= blockH)
        {
            for (int k = 0; k < 3; k++)
            {
              if (stoi(argv[3]) == 1)
              {
                    setBlock(getBrightest(img, x, y, blockW, blockH, k), x, y, blockW, blockH, k, newImg);
              }
              else
              {
                //gets the average of the pixel block and then sets all the pixels in that block to that value
                    setBlock(getAverage(img, x, y, blockW, blockH, k), x, y, blockW, blockH, k, newImg);
              }
            }
        }
    }

    if (argc >= 6)
    {
        string fileName(argv[5]);
        //fileName += ".png";
        imwrite(fileName, newImg);
    }
    else
    {
        char winName[] = "image";
        namedWindow(winName, WINDOW_AUTOSIZE);
        moveWindow(winName, 0, 0);

        imshow(winName, img);
        waitKey(0);
        imshow(winName, newImg);
        waitKey(0);
        imwrite("wtest.png", newImg);
    }
    return 0;
}
