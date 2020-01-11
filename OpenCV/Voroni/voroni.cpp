#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

vector <vector<int>> RandPoints(int height, int width, int nodeCount = 25)
{

    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> rowsRange(0, height);
    uniform_int_distribution <> colsRange(0, width);

    vector <vector<int>> points;
    for (int i = 0; i < nodeCount; i++)
    {                         
        vector <int> temp;    ;
        temp.push_back(colsRange(rng));
        temp.push_back(rowsRange(rng));
        points.push_back(temp);
    }
    return points;
}

double hypot(int x, int y, vector<int> coords)
{
    double xDiff = abs(coords.at(0) - x);
    double yDiff = abs(coords.at(1) - y);
    double xSqr = pow(xDiff, 2);
    double ySqr = pow(yDiff, 2);
    double hypSqr = ySqr + xSqr;
    return hypSqr;
}


void SetPixel(vector<int> coords, int x, int y, Mat &newImg, Mat oldImg)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        newImg.at<Vec3b>(y, x)[i] = oldImg.at<Vec3b>(coords.at(1), coords.at(0))[i];
    }
}

int main(int argc, char* argv[])
{
    /*
    argv[0]: program name (e.g. "pixeler")
    argv[1]: the image to be voronied
    argv[2]: number of nodes to use
    argv[3] (optional): output file name without this the program just displays the image for the viewer
     */
    
    if (argc < 3)
    {
        cout << "Error not enought arguments:\n1: the image to be voronied\n2: the number of nodes to use\n3 (optional): file name to be saved\n";
        return 2;
    }
    
    Mat img;
    img = imread(argv[1], IMREAD_COLOR);
    
    if (!img.data)
    {
        cout << "Error couldn't read the file\n";
        return 2;
    }

    Mat newImg = Mat(img.rows, img.cols, CV_8UC3, Scalar(100, 0, 0));

    vector <vector<int>> points = RandPoints(img.rows, img.cols, atoi(argv[2]));
    for (int x = 0; x < img.cols; x++)
    {
        for (int y = 0; y < img.rows; y++)
        {
            int closeNode = -1;
            double nearestDist = img.cols * img.rows;
            for (unsigned int i = 0; i < points.size(); i++)
            {
                double dist = hypot(x, y, points.at(i));
                if (dist == nearestDist)
                {
                    closeNode = -2;
                    break;
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
            else if (closeNode == -1)
            {
                cout << "Error closeNode: " << closeNode << endl;
                return 2;
            }
            else
            {
                SetPixel(points.at(closeNode), x, y, newImg, img);
            }
        }
    }

    //for (unsigned int i = 0; i < points.size(); i++)
    //{
        //vector <int> tempVec = points.at(i);
        //circle(newImg, Point(tempVec.at(1), tempVec.at(0)), 10, Scalar(0, 255, 0), FILLED, LINE_8);
    //}

    if (argc >= 4)
    {
        string fileName(argv[3]);
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
