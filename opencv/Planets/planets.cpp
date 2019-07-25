#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>

#include <time.h>
#include <random>
using namespace std;
using namespace cv;


class movLipse
{
    public:
        int thickness;
        int lineType;
        int angle;
        int width;
        int height;
        Point centre;
        Scalar colour;

        void setCentre(int y, int x)
        {
            centre = Point(x, y);
        }

        void addtoImg(Mat img)
        {
            ellipse(img, centre, Size(width,height), angle, 0, 360, colour, thickness, lineType);
        }
};


int main(int argc, char* argv[])
{
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> aRand(-30, 30);
    uniform_int_distribution <> rCol(-11, 11);
    uniform_int_distribution <> gCol(-11, 11);
    uniform_int_distribution <> bCol(-8, 8);


    int iniAngle = aRand(rng), itter = 0;
    int canSize = atoi(argv[1]);
    double rad = canSize/2.7, ang = atof(argv[3]);
    double height = abs(cos(3.14/ang)*rad);

    vector <movLipse> lipses;
    for (int i = 0; i < atoi(argv[2]); i++)
    {
        movLipse newOne;
        newOne.thickness = 1;
        newOne.angle = iniAngle;
        newOne.setCentre(canSize/2, (canSize*1.7)/2);
        newOne.width = rad +itter;
        newOne.height = height + cos(3.14/ang)*itter;
        newOne.colour = Scalar(rCol(rng)+29, gCol(rng)+27, bCol(rng)+20);
        lipses.push_back(newOne);
        itter += 1;
    }

    Mat frame = Mat::zeros(canSize, canSize*1.7, CV_8UC3);
    char windowName[] = "frame";
    namedWindow(windowName);
    moveWindow(windowName, 0, 0);
    circle(frame, Point((canSize*1.7)/2, canSize/2), canSize/6, Scalar(255,0,0), FILLED, LINE_8);

    for (unsigned int i = 0; i < lipses.size(); i++)
    {
        lipses.at(i).addtoImg(frame);
    }
    ellipse(frame, Point((canSize*1.7)/2, canSize/2), Size(canSize/6, canSize/6), 0, 180, 360, Scalar(255,0,0), FILLED, LINE_8);
    imshow(windowName, frame);
    waitKey(0);
    return 1;
}
