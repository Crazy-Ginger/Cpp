#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <time.h>
#include <random>
using namespace std;
using namespace cv;

class movLipse
{
    public:
        int thickness;
        int lineType = 8;
        int angle;
        int width;
        int height;
        Point centre;
        Scalar colour;

        void setCentre(int x, int y)
        {
            centre = Point(x, y);
        }

        void addtoImg(Mat img)
        {
            ellipse(img, centre, Size(height, width), angle, 0, 360, colour, thickness, lineType);
        }
};

int main(int argc, char* argv[])
{
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> angleRange(5, 180);
    uniform_int_distribution <> colourRange(0, 255);
    int canSize = atoi(argv[1]);
    vector <movLipse> lipses;
    for (int i = 0; i < 40; i++)
    {
        movLipse newOne;
        newOne.thickness = canSize/100;
        newOne.angle = angleRange(rng);
        newOne.setCentre(canSize/2, canSize/2);
        newOne.height = canSize/4;
        newOne.width = canSize/16;
        newOne.colour = Scalar(colourRange(rng), colourRange(rng), colourRange(rng));
        lipses.push_back(newOne);
    }
    for (double i = 0; i < 90; i++)
    {
        Mat frame = Mat::zeros(canSize, canSize, CV_8UC3);
        char windowName[] = "frame";
        namedWindow(windowName);
        moveWindow(windowName, 0, 0);
        for (unsigned int j = 0; j < lipses.size(); j++)
        {
            lipses.at(j).addtoImg(frame);
            lipses.at(j).angle ++;
        }
        imshow(windowName, frame);
        waitKey(30);
    }
    return 0;
}
