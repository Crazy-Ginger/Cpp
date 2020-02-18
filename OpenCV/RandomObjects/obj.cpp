#include <iostream>
#include <time.h>
#include <random>
#include <algorithm>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int height, width;

void ellipseAdd(Mat img)
{
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> rCol(0, 255);
    uniform_int_distribution <> linTh(-1, 10);
    uniform_int_distribution <> centre(0, width);
    uniform_int_distribution <> ang(0, 360);
    uniform_int_distribution <> rDims(1, width);

    ellipse(img, Point(centre(rng),centre(rng)), Size(rDims(rng),rDims(rng)), ang(rng), ang(rng), ang(rng), Scalar(rCol(rng),rCol(rng),rCol(rng)), linTh(rng), 4);
}


int main(int argc, char* argv[])
{
    int dim = atoi(argv[1]);
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> objNum(dim*2, dim*10);
    uniform_int_distribution <> randObj(0, 10);
    
    height = dim; width = dim*1.77;

    Mat coFrame = Mat::zeros(height, width, CV_8UC3);
    char windowName[] = "random image";
    string choice = argv[2];
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    namedWindow(windowName);
    moveWindow(windowName, 0, 0);

    for (int i = 0; i < objNum(rng); i++)
    {
        unsigned int randNum = randObj(rng);
        if  (randNum == 2)
        {
            ellipseAdd(coFrame);
        }

    }

    if (choice == "colour" || choice == "co")
    {
        imshow(windowName, coFrame);
    }
    else
    {
        Mat gFrame;
        cvtColor(coFrame, gFrame, COLOR_BGR2GRAY);

        if (choice == "ca" || choice == "cannied")
        {
            Mat caFrame;
            Canny(gFrame, caFrame, 50, 150, 5);
            imshow(windowName, caFrame);
        }
        else if (choice == "g" || choice == "gr")
        {
            imshow(windowName, gFrame);
        }
        else
        {
            cout << "Error\n";
        }
    }
    waitKey(0);
    return 0;
}
