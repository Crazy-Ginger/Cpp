#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <string> //for userinput
#include <algorithm> //converting user input to lowercase
//for the random generation of the ellipses
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
    uniform_int_distribution <> aRand(5, 180);
    uniform_int_distribution <> coRand(0, 255);
    
    string choice;
    int canSize;
    if (argc > 1)
    {
        choice =  argv[1];

        //takes the user input size for the image
        canSize = atoi(argv[2]);
    }
    else
    {
        cout << "Error inputs required\n";
        cout << "Inputs needed:\n1) choice of col\n2) dimension of frame\n";
        return 0;
    }

    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    //creates a vector of the lipses class to allow many to be displayed
    vector <movLipse> lipses;

    //adds the ellipses to the vector of them and customises them before they're added
    for (int i = 0; i < 10; i++)
    {
        movLipse newOne;
        newOne.thickness = canSize/100;
        newOne.angle = aRand(rng);
        newOne.setCentre(canSize/2, canSize/2);
        newOne.height = canSize/2 -20;
        newOne.width = canSize/8 -20;
        if (choice != "cannied" || choice != "ca")
        {
            newOne.colour = Scalar(coRand(rng), coRand(rng), coRand(rng));
        }
        else
        {
            newOne.colour = Scalar(255, 255, 255);
        }
        lipses.push_back(newOne);
    }
    cout << "Added ellipses\n";
   
    for (double i = 0; i < 360; i++)
    {
        //creates the basic frame that will contain the basic ellipes
        Mat coFrame = Mat::zeros(canSize, canSize, CV_8UC3);

        //sets the name of the images to be shown and establishes the window and resets its position
        char windowName[] = "frame";
        namedWindow(windowName);
        moveWindow(windowName, 0, 0);

        //adds all the ellipses to the image
        for (unsigned int j = 0; j < lipses.size(); j++)
        {
            //adds the ellipse to the image
            lipses.at(j).addtoImg(coFrame);
            //adds to the angle for its next display time
            lipses.at(j).angle += j/4 +1;
        }


        if (choice == "colour" || choice == "co")
        {
            imshow(windowName, coFrame);
            waitKey(10);
        }
        else
        {
            //initiallises the other mats to hold the greyscale, cannied and filled ellipses
            Mat gFrame, caFrame;

            //greyscales and then blurs the entire image (to be cannied) and saves it over the grey image mat
            cvtColor(coFrame, gFrame, COLOR_BGR2GRAY);
            
            if (choice == "grey" || choice == "g")
            {
                imshow(windowName, gFrame);
                waitKey(40);
            }
            else if (choice == "cannied" || choice == "ca")
            {
                //blur(gFrame, gFrame, Size(2,2));
                //cannies the entire image and saves it as a new image mat
                Canny(gFrame, caFrame, 100, 140, 5);
                
                imshow(windowName, caFrame);
                waitKey(40);
            }
            else
            {
                cout << "invalid input\n";
            }
        }
    }
    return 0;
}
