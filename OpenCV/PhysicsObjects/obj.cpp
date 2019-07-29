#include <iostream>
#include <vector>

#include <random>
#include <time.h>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int width, height;

class ball
{
    public:
        //constructor called when new object is instantiated
        ball()
        {
            random_device rd;
            default_random_engine rng(rd());
            uniform_int_distribution <> wCoord(width/5, 4*(width/5));
            uniform_int_distribution <> hCoord(height/5, 4*(height/5));
            setCen(wCoord(rng), hCoord(rng));

            //should generate a random direction for the ball
            uniform_int_distribution <> boolGen(0, 1);
            if (boolGen(rng) == 0)
            {
                down = true;
            }
            else down = false;

            if (boolGen(rng) == 0)
            {
                right = true;
            }
            else right = false;
        }
        Point centre;
        Scalar colour;
        int rad;
        int xcoord, ycoord;
        bool right , down;

        //sets the centre of the object and assigns it to the variables
        void setCen(int x, int y)
        {
            centre = Point(x,y);
            xcoord = x;
            ycoord = y;
        }
        //sets the colour of the circle
        void setColour(int r, int g, int b)
        {
            colour = Scalar(r, g, b);
        }
        //adds the object to the image
        void addtoImg(Mat img)
        {
            circle(img, centre, rad, colour, FILLED, LINE_8);
        }
        //checks the object isn't in a wall
        void wallCol()
        {
            if (rad + xcoord > width)
            {
                right = false;
            }
            if (rad + ycoord > height)
            {
                down = false;
            }
            if (xcoord - rad < 0)
            {
                right = true;
            }
            if (ycoord - rad < 0)
            {
                down = true;
            }

            //int x = obj.xcoord, y = obj.ycoord;
            if (!right)
            {
                setCen(--xcoord, ycoord);
            }
            if (!down)
            {
                setCen(xcoord, --ycoord);
            }
            if (down)
            {
                setCen(xcoord, ++ycoord);
            }
            if (right)
            {
                setCen(++xcoord, ycoord);
            }
        }
};


int main(int argc, char* argv[])
{   
    //checks for the correct number of inputs
    if (argc != 5)
    {
        cout << "Inputs required\n1st Window Height\n2nd Window width\n3rd Circle radius\n4th Speed\n";
        return -1;
    }

    height = atoi(argv[1]);
    width = atoi(argv[2]);
    int rad = atoi(argv[3]);

    //initialise physics object
    ball obj;
    obj.rad = rad;
    obj.setColour(100, 150, 200);

    //infinite loop
    for (;;)
    {
        //cout << "centre: " << obj.centre << endl;
        Mat canvas = Mat::zeros(height, width, CV_8UC3);
        char name[] = "frame";
        namedWindow(name);
        moveWindow(name, 0, 0);

        obj.addtoImg(canvas);

        obj.wallCol();

        imshow(name, canvas);
        waitKey(atoi(argv[4]));
    }
    return 0;
}
