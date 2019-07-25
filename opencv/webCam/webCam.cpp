#include <iostream>
#include <vector>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    Mat frame, cFrame;
    VideoCapture cap;
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    cap.open(deviceID + apiID);

    if (!cap.isOpened())
    {
        cout << "Error no luck reading\n";
        return -1;
    }

    while(true)
    {
        cap.read(frame); 
        if (frame.empty())
        {
            cout << "Blank frame\n";
            break;
        }
        cvtColor(frame, cFrame, COLOR_BGR2GRAY);
        blur(cFrame, cFrame, Size(2,2));
        Canny(cFrame, cFrame, 100, 300, 5);

        char windowName[] = "frame";
        namedWindow(windowName);
        moveWindow(windowName, 0, 0);
        imshow(windowName, cFrame);
        waitKey(2);
    }
    return 0;
}