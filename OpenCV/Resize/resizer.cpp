#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
    /*
     argv[1]: image to read
     argv[2]: width to resize to
     argv[3]: height to resize to
     argv[4]: (optional) ouptut file
     */

    if (argc < 4)
    {
        cout << "Error not enough arguments.\n1: image to read\n2: width to resize to\n3: height to resize to\n4: (optional) ouptut file\n";
        return 2;
    }
    int blockW = stoi(argv[2]);
    int blockH = stoi(argv[3]);
    
    Mat img;
    img = imread(argv[1], IMREAD_COLOR);
    
    if (!img.data)
    {
        cout << "Error couldn't read the file\n";
        return 2;
    }

    Mat newImg;
    Size size(blockW, blockH);
    resize(img, newImg, size);

    if (argc >= 5)
    {
        string fileName(argv[4]);
        //fileName += ".png";
        imwrite(fileName, newImg);
    }
    else
    {
        //ensures the window is always placed in the top left corner and the name can be reused later in the program
        char winName[] = "image";
        namedWindow(winName, WINDOW_AUTOSIZE);
        moveWindow(winName, 0, 0);

        imshow(winName, img);
        waitKey(0);
        imshow(winName, newImg);
        waitKey(0);
        imwrite("wtest.png", newImg);
    }
    return 0;
}
