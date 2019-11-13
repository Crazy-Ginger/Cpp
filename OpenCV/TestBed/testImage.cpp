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
           for (uint i = 0; i < 3; i++)
           {
               totals[i] += img.at<Vec3b>(y, x)[i];
           }

        }
    }
    cout << "Totals: \n";
    for (uint i = 0; i < 3; i++)
    {
        cout << totals[i] << endl;
        cout << "Average: " << totals[i]/(img.cols*img.rows) << endl;
    }
    return 0;
}
