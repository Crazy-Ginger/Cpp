#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

//class movingLipse
//{
    //public:
        //int thickness;
        //int lineType = 8;
        //int angle;
        //int width;
        //int height;
    //public:
        //void setThick(int x)
        //{
            //thickness = x;
        //}
        //void setDim(int h, int w)
        //{
            //height = h;
            //width = w;
        //}
        //void setAngle(int a)
        //{
            //angle = a;
        //}
//};

int main(int argc, char* argv[])
{
    //movingLipse lips1;
    //lips1.setThick(3);
    //lips1.setDim(atoi(argv[1]), atoi(argv[2]));
    //lips1.setAngle(0);
    cout << "Apparently thats all set\n";

    
    for (double i = 0; i < 180; i++)
    {
        Mat frame = Mat::zeros(700, 700, CV_8UC3);
        char windowName[] = "what up";
        namedWindow(windowName);
        moveWindow(windowName, 0, 0);
        ellipse(frame, Point(350, 350), Size(175, 44), i, 0, 360, Scalar(255, 0, 0), 2, 8);
        imshow(windowName, frame);
        waitKey(20);
    }
    return 0;
}
