#include <iostream>
#include <string>
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
        int width;
        int height;
        Point centre;
        Scalar colour;
        bool down = false;
        void setCentre(int y, int x)
        {
            centre = Point(x, y);
        }

        void addtoImg(Mat img, int angle)
        {
            ellipse(img, centre, Size(width,height), angle, 0, 360, colour, thickness, lineType);
        }
};


int main(int argc, char* argv[])
{
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> aRand(-20, 20);
    uniform_int_distribution <> rCol(-11, 11);
    uniform_int_distribution <> gCol(-11, 11);
    uniform_int_distribution <> bCol(-8, 8);


    int itter = 0;
    int canSize = atoi(argv[1]);
    double rad = canSize/2.7, ang = atof(argv[3]);
    //double height = abs(cos(3.14/ang)*rad);

    //establishes vector of ellipses that slowly increase in size to create the ring look
    vector <movLipse> rings;
    for (int i = 0; i < atoi(argv[2]); i++)
   {
        movLipse newOne;
        newOne.thickness = 1;
        newOne.setCentre(canSize/2, (canSize*1.7)/2);
        newOne.width = rad +itter;
        newOne.height = (rad+itter)*abs(cos(ang));
        //newOne.width = rad +itter;
        //newOne.height = height + cos(3.14/ang)*itter;
        newOne.colour = Scalar(bCol(rng)+20, gCol(rng)+27, rCol(rng)+29);
        rings.push_back(newOne);
        itter += 1;
    }

    //bool down = true;
    //angSpeed = 3;
    //creates loop to allow oscilation
    double doubItter = 0;
    int rAngle;
    for (;;)
    {
        //sets the new angle of the rings
        rAngle = 20 * cos(doubItter);

        //establishes all the image details and moves the window
        Mat frame = Mat::zeros(canSize, canSize*1.7, CV_8UC3);
        char windowName[] = "frame";
        namedWindow(windowName);
        moveWindow(windowName, 0, 0);

        //adds a blue circle to the image to represent the planet
        //could do more such as add rings onto planet using ellipses
        circle(frame, Point((canSize*1.7)/2, canSize/2), canSize/6.5, Scalar(255,0,0), FILLED, LINE_8);
        
        //adds all the ellipses to the image
        for (unsigned int i = 0; i < rings.size(); i++)
        {
            //adds the lipses to the image
            rings.at(i).addtoImg(frame, rAngle);
        } 

        //adds another elipse to the image to cover back of the ellipses
        //this causes the edge of the planet to move for some reason, probs to do with the way shapes are drawn
        ellipse(frame, Point((canSize*1.7)/2, canSize/2), Size(canSize/6.5, canSize/6.5), rAngle, 180, 360, Scalar(255,0,0), FILLED, LINE_8);
        
        //displays the image then waits 10 milliseconds, changed to when moved to using trig to change angle
        imshow(windowName, frame);
        waitKey(10);

        //itterates the angle by increasing an approx in radians
        if (doubItter > 3.141*2)
        {
            //set above 0 to avoid bouncing error
            doubItter = 0.04;
        }
        else 
        {
            //increases the angle to make the rings appear to move, incorrect but a decent approx for now
            doubItter += 0.04;
        }
    }
    return 1;
}
