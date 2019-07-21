#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

void MyEllipse( Mat img, double angle);
void MyFilledCircle(Mat img, Point center);
void MyPolygon(Mat img);
void MyLine(Mat img, Point start, Point end);

int w = 400;

int main(void)
{
    char atom_window[] = "Drawing 1: Atom";

    Mat atom_image = Mat::zeros(w, w, CV_8UC3);

    MyEllipse(atom_image, 90);
    MyEllipse(atom_image, 0);
    MyEllipse(atom_image, 45);
    MyEllipse(atom_image, -45);

    MyFilledCircle(atom_image, Point(w/2, w/2));

    imshow(atom_window, atom_image);
    waitKey(0);
    return 0;
}

void MyEllipse( Mat img, double angle )
{
  int thickness = 2;
  int lineType = 8;
  ellipse( img,
       Point( w/2, w/2 ),
       Size( w/4, w/16 ),
       angle,
       0,
       360,
       Scalar( 255, 0, 0 ),
       thickness,
       lineType );
}

void MyFilledCircle( Mat img, Point center )
{
  circle( img,
      center,
      w/32,
      Scalar( 0, 0, 255 ),
      FILLED,
      LINE_8 );
}


