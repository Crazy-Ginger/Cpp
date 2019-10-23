#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void setBlock()
{

}


int getBlock(Mat img, int widths, int height, int blockW, int blockH, int channel)
{
    int total = 0;
    for (int x = 0; x < blockW; x++)
    {
        for (int y =0;y < blockW; y++)
        {
            total += img.at<Vec3b>(Point(height+y, widths+x))[channel];
        }
    }
    int average = total / (blockH * blockW);
    return average;
}

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
    int height = img.rows;
    int widths = img.cols;
    
    Mat newImg = Mat(height, widths, CV_8UC3, Scalar(0,0,0));

    char release;
    for(int x = 0; x < widths - blockW; x+= blockW)
    {
        for (int y = 0; y < height - blockH; y+= blockH)
        {
            Vec3b bgrPixel = img.at<Vec3b>(y, x);
            for (int k = 0; k < 3; k++)
            {
                setBlock(getBlock(img, x, y, blockW, blockH, k), x, y, blockW, blockH, k);
            }
            cout << bgrPixel << endl;
            cin >> release;
        }
    }

    namedWindow( "Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", img);
    waitKey(0);
    return 0;
}
