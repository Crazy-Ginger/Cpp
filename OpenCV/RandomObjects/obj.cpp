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

class ellipses
{
    public:
        ellipses(Mat img)
        {
            random_device rd;
            default_random_engine rng(rd());
            uniform_int_distribution <> rColour(0, 255);
            uniform_int_distribution <> lineThick(-1, 20);
            uniform_int_distribution <> centre(0, width);
            uniform_int_distribution <> angles(0, 360);

            
        }
};

int main(int argc, char* argv[])
{
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> rColour(0, 255);
    uniform_int_distribution <> objNum(700, 7000);
    uniform_int_distribution <> dic();
    
    int dim = atoi(argv[1]);
    height = dim; width = dim;

    Mat coFrame = Mat::zeros(dim, dim, CV_8UC3);
    char windowName[] = "random image";
    string choice = argv[2];
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    namedWindow(windowName);
    moveWindow(windowName, 0, 0);

    if (choice == "g" || choice == "gr")
    {
        Mat gFrame;
    }
    else if (choice == "ca" || choice == "cannied")
    {
        Mat gFrame, caFrame;
    }
    
    return 0;
}
