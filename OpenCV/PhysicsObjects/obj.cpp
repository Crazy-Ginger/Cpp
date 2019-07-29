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
            uniform_int_distribution <> velGen(-10, 10);
            xVel = velGen(rng);
            yVel = velGen(rng);
            cout << "xVel: " << xVel << "\tyVel: "<< yVel << endl;
        }
        Point centre;
        Scalar colour;
        int rad;
        int xCoord, yCoord;
        bool right , down;
        int xVel, yVel;

        //sets the centre of the object and assigns it to the variables
        void setCen(int x, int y)
        {
            centre = Point(x,y);
            xCoord = x;
            yCoord = y;
        }
        //sets the colour of the circle
        void setColour(int r, int g, int b)
        {
            //colour is (B, G, R)
            colour = Scalar(r, g, b);
        }
        //adds the object to the image
        void addtoImg(Mat img)
        {
            circle(img, centre, rad, colour, FILLED, LINE_8);
        }
        //checks the object isn't in a wall
        void wallCheck()
        {
            if (rad + xCoord > width)
            {
                xVel = -1 * xVel;
            }
            if (rad + yCoord > height)
            {
                yVel = -1*yVel;
            }
            if (xCoord - rad < 0)
            {
                xVel = -1*xVel;
            }
            if (yCoord - rad < 0)
            {
                yVel = -1*yVel;
            }
        }
        //moves the centre by the velocity of the ball
        void move()
        {
            setCen(xCoord + xVel, yCoord + yVel);
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
    obj.setColour(255, 255, 255);

    //infinite loop
    for (;;)
    {
        //generates the mat and the window for the display image
        Mat canvas = Mat::zeros(height, width, CV_8UC3);
        char name[] = "frame";
        namedWindow(name);
        moveWindow(name, 0, 0);

        obj.addtoImg(canvas);

        //checks the ball isnt in a wall and then moves the ball for the next time
        obj.wallCheck();
        obj.move();

        imshow(name, canvas);
        waitKey(atoi(argv[4]));
    }
    return 0;
}
