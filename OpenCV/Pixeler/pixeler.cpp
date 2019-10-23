#include <iostream>

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
    int average = (total / (blockH * blockW));
    return average;
}

int main(int argc, char* argv[])
{
    //if (argc != 4)
    //{
        //cout << "Input's required:\n1.Pixelating block Height\n2.Pixelating block Width\n";
    //}

    int blockH = stoi(argv[1]);
    int blockW = stoi(argv[2]);
    
    //cout << argv[3] << endl;
    
    Mat img;
    img = imread(argv[3], IMREAD_COLOR);
    //if (!img.data)
    //{
        //cout << "Error couldn't read the file\n";
        //return 1;
    //}
    int height = img.rows;
    int widths = img.cols;
    
    Mat newImg = Mat(height, widths, CV_8UC3, Scalar(0,0,0));

    for(int x = 0; x < widths - blockW; x+= blockW)
    {
        for (int y = 0; y < height - blockH; y+= blockH)
        {
            for (int k = 0; k < 3; k++)
            {
                setBlock(getBlock(img, x, y, blockW, blockH, k), x, y, blockW, blockH, k, newImg);
            }
        }
    }

    char winName[] = "image";
    namedWindow(winName, WINDOW_AUTOSIZE);
    moveWindow(winName, 0, 0);

    //imshow(winName, img);
    //waitKey(0);
    imshow(winName, newImg);
    waitKey(0);
    imwrite("wtest.png", newImg);
    return 0;
}
