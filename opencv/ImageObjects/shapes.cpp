#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <time.h>
#include <random>
using namespace std;
using namespace cv;

void MyEllipse( Mat img, double angle);
void MyFilledCircle(Mat img, Point center);
void MyLine(Mat img, Point start, Point end, int thickness);

int w;

int main(int argc, char* argv[])
{
    char atom_window[] = "Drawing 1: Atom";
    w = atoi(argv[1]);
    Mat atom_image = Mat::zeros(w, w, CV_8UC3);

    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> range(5, 60);

    for (double i = 0; i< 360; i+=range(rng))
    {
        MyEllipse(atom_image, i);
    }
    //MyEllipse(atom_image, 0);
    //MyEllipse(atom_image, 45);
    //MyEllipse(atom_image, -45);

    MyFilledCircle(atom_image, Point(w/2, w/2));

    namedWindow(atom_window);
    moveWindow(atom_window, 0, 0);
    imshow(atom_window, atom_image);
    cout << "Look a shape\n";
    waitKey(0);
    return 0;
}

void MyEllipse( Mat img, double angle )
{
  int thickness = 2;
  int lineType = 8;
  ellipse(img, Point( w/2, w/2 ), Size( w/4, w/16 ), angle, 0, 360, Scalar( 255, 0, 0 ), thickness, lineType);
}

void MyFilledCircle( Mat img, Point center )
{
  circle(img, center, w/32, Scalar( 0, 0, 255 ), FILLED, LINE_8);
}

void MyLine(Mat img, Point start, Point end, int thickness = 8)
{
    line(img, start, end, Scalar(255, 0, 0), thickness);
}
