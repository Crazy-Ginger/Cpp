#include <iostream>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

class ball
{
    public:
        Point centre;
        Scalar colour;
        int rad;
        int xcoord, ycoord;

    void setCen(int x, int y)
    {
        centre = Point(x,y);
        xcoord = x;
        ycoord = y;
    }
    void setColour(int r, int g, int b)
    {
        colour = Scalar(r, g, b);
    }
    void addtoImg(Mat img)
    {
        circle(img, centre, rad, colour, FILLED, LINE_8);
    }
};

unsigned int t = 0;

int main(int argc, char* argv[])
{   
    int height = atoi(argv[1]), width = atoi(argv[2]), rad = atoi(argv[3]);
    
    //initialise physics object
    ball obj;
    obj.rad = rad;
    obj.setCen(width/2, height/2);
    obj.setColour(100, 150, 200);

    bool right = true, down = true;
    //infinite loop
    for (;;)
    {
        //cout << "centre: " << obj.centre << endl;
        Mat canvas = Mat::zeros(height, width, CV_8UC3);
        char name[] = "frame";
        namedWindow(name);
        moveWindow(name, 0, 0);

        obj.addtoImg(canvas);
        
        if (rad + obj.xcoord > width)
        {
            right = false;
        }
        if (rad + obj.ycoord > height)
        {
            down = false;
        }
        if (obj.xcoord - rad < 0)
        {
            right = true;
        }
        if (obj.ycoord - rad < 0)
        {
            down = true;
        }

        //int x = obj.xcoord, y = obj.ycoord;
        if (!right)
        {
            obj.setCen(--obj.xcoord, obj.ycoord);
        }
        if (!down)
        {
            obj.setCen(obj.xcoord, --obj.ycoord);
        }
        if (down)
        {
            obj.setCen(obj.xcoord, ++obj.ycoord);
        }
        if (right)
        {
            obj.setCen(++obj.xcoord, obj.ycoord);
        }

        imshow(name, canvas);
        waitKey(atoi(argv[4]));
    }
    return 0;
}
