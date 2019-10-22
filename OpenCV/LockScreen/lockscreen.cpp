#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;



int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        cout << "Input's required:\n1.Pixelating block Height\n2.Pixelating block Width\n";
    }

    int blockH = stoi(argv[1]);
    int blockW = stoi(argv[2]);

    cout << argv[3] << endl;
    
    Mat img;
    img = imread(argv[3], IMREAD_COLOR);
    if (!img.data)
    {
        cout << "Error couldn't read the file\n";
        return 1;
    }
    //int height = img.rows;
    //int widths = img.cols;
    
    char release;
    //for(int x = 0; x < widths - blockW; x+= blockW)
    //{
        //for (int y = 0; y < height - blockH; y+= blockH)
        //{
            ////Vec3b bgrPixel = img.at<Vec3b>(y, x);
            ////cout << bgrPixel << endl;
            //cin >> release;
        //}
    //}

    namedWindow( "Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", img);
    waitKey(0);
    return 0;
}
