#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

class movingLipse
{
    public:
        int thickness;
        int lineType = 8;
        int angle;
        int width;
        int height;
    public:
        void setThick(int x)
        {
            thickness = x;
        }
        void setDim(int h, int w)
        {
            height = h;
            width = w;
        }
        void setAngle(int a)
        {
            angle = a;
        }
};

int main(int argc, char* argv[])
{
    movingLipse lips1;
    lips1.setThick(3);
    lips1.setDim(atoi(argv[1]), atoi(argv[2]));
    lips1.setAngle(0);
    cout << "Apparently thats all set\n";
    cout << lips1.lineType << "\t" << lips1.angle << "\t" << lips1.width << ", " << lips1.height << endl;
}
