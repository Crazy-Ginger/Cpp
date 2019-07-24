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
    //establishes the random stuff to allow randomisation of the start angle and colour of the ellipses
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> angleRange(5, 180);
    uniform_int_distribution <> colourRange(0, 255);

    //takes the user input size for the image
    int canSize = atoi(argv[1]);
    //creates a vector of the lipses class to allow many to be displayed
    vector <movLipse> lipses;

    //adds the ellipses to the vector of them and customises them before they're added
    for (int i = 0; i < 10; i++)
    {
        movLipse newOne;
        newOne.thickness = canSize/100;
        newOne.angle = angleRange(rng);
        newOne.setCentre(canSize/2, canSize/2);
        newOne.height = canSize/2 -20;
        newOne.width = canSize/8 -20;
        newOne.colour = Scalar(255, 255, 255);
        lipses.push_back(newOne);
    }
    
    
    for (double i = 0; i < 360; i++)
    {
        Point seed(3,3);
        //creates the basic frame that will contain the basic ellipes
        Mat frame = Mat::zeros(canSize, canSize, CV_8UC3);
        //initiallises the other mats to hold the greyscale, cannied and filled ellipses
        Mat greyFrame, cframe, mask, fillFrame;

        //sets the name of the images to be shown and establishes the window and resets its position
        char windowName[] = "frame";
        namedWindow(windowName);
        moveWindow(windowName, 0, 0);

        //adds all the ellipses to the image
        for (unsigned int j = 0; j < lipses.size(); j++)
        {
            //adds the ellipse to the image
            lipses.at(j).addtoImg(frame);
            //adds to the angle for its next display time
            lipses.at(j).angle += j/2 +1;
        }
        //greyscales and then blurs the entire image (to be cannied) and saves it over the grey image mat
        cvtColor(frame, greyFrame, COLOR_BGR2GRAY);
        blur(greyFrame, greyFrame, Size(2,2));
        //cannies the entire image and saves it as a new image mat
        Canny(greyFrame, cframe, 10, 30, 5);
        
        /*{
        //tryied to create code that would fill the inside of the cannied ellipses but has problems with the edges being incomplete
        //copies the cannied image onto mask and then...?
        mask = cframe;
        fillFrame = cframe;
        copyMakeBorder(mask, mask, 1, 1, 1, 1, BORDER_REPLICATE);

        //creating a bunch of throwaway variables and gets a point that should be inside the ellipses

        int ellipseEdge = 0;
        bool passedWhite = false, cont = false;
        while (!cont)
        {
            if ((fillFrame.at<int>(canSize/2, ellipseEdge) == 0) && passedWhite)
            {
                cont = true;
            }
            else if (fillFrame.at<int>(canSize/2, ellipseEdge) !=0)
            {
                passedWhite = true;
                ellipseEdge ++;
            }
            else 
            {
                ellipseEdge++;
            }
        }
        Rect recta;
        //fills the spaces with white block
        floodFill(fillFrame, mask, Point(canSize/2, ellipseEdge), Scalar(100), &recta, Scalar(0), Scalar(230));

        Mat colourFill;
        cvtColor(fillFrame, colourFill, COLOR_GRAY2BGR);
        circle(colourFill, Point(canSize/2, ellipseEdge), 5, Scalar(0,0,255),FILLED, LINE_8);
        //displays the image and then waits 50 milliseconds before destroing it and running again
        imshow(windowName, colourFill);}*/
        imshow(windowName, cframe);
        waitKey(40);
    }
    return 0;
}
