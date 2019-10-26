#include <iostream>
using namespace std;

int main()
{
    int total = 5333;
    int length = 5;
    int width = 10;
    int area = length*width;
    int average = total/area;

    cout << "average= " << total << "/" << area << endl;
    cout << "average: " << average << endl;
    
    return 0;
}

