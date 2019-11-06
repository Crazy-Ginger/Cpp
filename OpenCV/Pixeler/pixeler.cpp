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
            img.at<Vec3b>(startH+h, startW+w)[channel] = value;
        }
    }
}

int getBlock(Mat img, int widths, int height, int blockW, int blockH, int channel)
{
    int total = 0;
    for (int x = 0; x < blockW; x++)
    {
        for (int y =0;y < blockW; y++)
        {
            total += img.at<Vec3b>(height+y, widths+x)[channel];
        }
    }
    int area = blockH * blockW;
    int average = (total / area);
    return average;
}

int main(int argc, char* argv[])
{
    int blockH = stoi(argv[1]);
    int blockW = stoi(argv[2]);
    
    Mat img;
    img = imread(argv[3], IMREAD_COLOR);
    if (!img.data)
    {
        cout << "Error couldn't read the file\n";
        return 2;
    }
    int height = img.rows;
    int widths = img.cols;
    
    Mat newImg = Mat(height, widths, CV_8UC3, Scalar(0,0,0));

    for(int x = 0; x < widths - blockW; x+= blockW)
    {
        for (int y = 0; y < height - blockH; y+= blockH)
        {
            for (int k = 0; k < 3; k++)
            {
                //gets the average of the pixel block and then sets all the pixels in that block to that value
                setBlock(getBlock(img, x, y, blockW, blockH, k), x, y, blockW, blockH, k, newImg);
            }
        }
    }
    cout << "Old value: " << img.at<Vec3b>(100,100) << endl;
    cout << "New value: " << newImg.at<Vec3b>(100,100) << endl;
    if (argc == 5)
    {
        string fileName(argv[4]);
        fileName += ".png";
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
