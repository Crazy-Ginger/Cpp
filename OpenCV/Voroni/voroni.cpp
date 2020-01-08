#include <iostream>
#include <string>
#include <cmath>
#include <random>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

int * points(int height, int width)
{
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> lengthRange(30, 100);
    int length = lengthRange(rng);
    int points[length][1];
    for (uint i = 0; i < sizeof(points); i++)
    {

    }
    return points;
}

int main(int argc, char* argv[])
{
    /*
    argv[0]: program name (e.g. "pixeler")
    argv[1]: the image to be pixelated
    argv[2] (optional): output file name without this the program just displays the image for the viewer
     */

    if (argc < 3)
    {
        cout << "Error not enought arguments:\n1: the image to be voronied\n2 (optional): file name to be saved\n";
        return 2;
    }
    
    Mat img;
    img = imread(argv[1], IMREAD_COLOR);
    
    if (!img.data)
    {
        cout << "Error couldn't read the file\n";
        return 2;
    }

    Mat newImg = Mat(img.cols, img.rows, CV_8UC3, Scalar(0,0,0));

    //loop or something here
    
    if (argc >= 3)
    {
        string fileName(argv[2]);
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
    }
    return 0;
}
