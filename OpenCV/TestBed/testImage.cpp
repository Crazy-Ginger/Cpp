#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
    int totals[3] = {0,0,0};
    Mat img;
    img = imread(argv[1], IMREAD_COLOR);
    if (!img.data)
    {
        cout << "Error couldn't read the file\n";
        return 2;
    }

    for (int x = 0; x <img.cols; x++)
    {
        for (int y = 0; y < img.rows; y++)
        {
           for (uint i = 0; i < sizeof(totals); i++)
           {
               totals[i] += img.at<Vec3b>(y, x)[i];
           }

        }
    }
    cout << "Totols: \n";
    for (uint i = 0; i < sizeof(totals); i++)
    {
        cout << totals[i] << endl;
    }
    return 0;
}

