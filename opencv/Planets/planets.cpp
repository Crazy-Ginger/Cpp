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
        bool down = false;
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
    uniform_int_distribution <> aRand(-20, 20);
    uniform_int_distribution <> rCol(-11, 11);
    uniform_int_distribution <> gCol(-11, 11);
    uniform_int_distribution <> bCol(-8, 8);


    int iniAngle = aRand(rng), itter = 0;
    int canSize = atoi(argv[1]);
    double rad = canSize/2.7, ang = atof(argv[3]);
    double height = abs(cos(3.14/ang)*rad);

    //establishes vector of ellipses that slowly increase in size to create the ring look
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

    //creates loop to allow oscilation
    for (;;)
    {
        //establishes all the image stuff such as planet and move the window
        Mat frame = Mat::zeros(canSize, canSize*1.7, CV_8UC3);
        char windowName[] = "frame";
        namedWindow(windowName);
        moveWindow(windowName, 0, 0);
        circle(frame, Point((canSize*1.7)/2, canSize/2), canSize/6.5, Scalar(255,0,0), FILLED, LINE_8);
        
        //adds all the ellipses to the image
        for (unsigned int i = 0; i < lipses.size(); i++)
        {
            //adds the lipses to the image
            lipses.at(i).addtoImg(frame);
            
            //checks if the lipses are at the max on min height and then if they're heading up or down and then increments or decrements the angle for the next frame
            if (lipses.at(i).angle > 20)
            {
                lipses.at(i).angle--;
                lipses.at(i).down =  true;
            }
            else if (lipses.at(i).angle < -20)
            {
                lipses.at(i).angle++;
                lipses.at(i).down = false;
            }
            else if (lipses.at(i).down)
            {
                lipses.at(i).angle--;
            }
            else if (!lipses.at(i).down)
            {
                lipses.at(i).angle++;
            }
            else
            {
                cout << "um... something gone wrong at: " << i << endl;
            }
        }
        //adds another elipse to the image to cover back of the ellipses
        ellipse(frame, Point((canSize*1.7)/2, canSize/2), Size(canSize/6.5, canSize/6.5), 0, 180, 360, Scalar(255,0,0), FILLED, LINE_8);
        
        //displays the image then waits 40 milliseconds
        imshow(windowName, frame);
        waitKey(60);
    }
    return 1;
}
