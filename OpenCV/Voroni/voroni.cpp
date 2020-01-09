#include <iostream>
#include <string>
#include <cmath>
#include <random>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

vector <vector<int>> RandPoints(int height, int width)
{
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> nodeRange(30, 100);
    uniform_int_distribution <> heightRange(0, height);
    uniform_int_distribution <> widthRange(0, width);
    int nodeCount = nodeRange(rng);
    vector <vector<int>> points;
    for (int i = 0; i < nodeCount; i++)
    {
        vector <int> temp;
        temp.push_back(widthRange(rng));
        temp.push_back(heightRange(rng));
        points.push_back(temp);
    }
    return points;
}


void SetPixel(int pointX, int pointY, int x, int y, Mat &img)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        img.at<Vec3b>(y, x)[i] = img.at<Vec3b>(pointY, pointX)[i];
    }
}


int main(int argc, char* argv[])
{
    /*
    argv[0]: program name (e.g. "pixeler")
    argv[1]: the image to be voronied
    argv[2] (optional): output file name without this the program just displays the image for the viewer
     */

    if (argc < 2)
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

    vector <vector<int>> points = RandPoints(img.rows, img.cols);
    
    for (int x = 0; x < img.cols; x++)
    {
        for (int y = 0; y < img.rows; y++)
        {
            int closeNode = -1;
            unsigned int nearestDist = img.cols * img.rows;
            for (unsigned int i = 0; i < points.size(); i++)
            {
                unsigned int dist = sqrt(pow((points.at(i).at(0)-x),2)+pow((points.at(i).at(1)-y), 2));
                if (dist == nearestDist)
                {
                    closeNode = -2;
                }
                else if (dist < nearestDist)
                {
                    nearestDist = dist;
                    closeNode = i;
                }
            }
            if (closeNode == -2)
            {
                continue;
            }
            else
            {
                SetPixel(points.at(closeNode).at(0), points.at(closeNode).at(1),x, y, newImg);
            }
        }
    }

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
