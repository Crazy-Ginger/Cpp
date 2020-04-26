#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char* argv[])
{
    clock_t clock_start, clock_end;
    int length = stoi(argv[1]);
    clock_start = clock();
    cout << length << endl;
    clock_end = clock();
    float tickDiff((float)clock_end - (float)clock_start);
    float clockDiff = tickDiff / CLOCKS_PER_SEC;
    cout << "Clock count: " << tickDiff << "\tTime: " << clockDiff << endl;

    clock_start = clock();
    cout << stoi(argv[1]) << endl;
    clock_end = clock();
    tickDiff = (float)clock_end - (float)clock_start;
    clockDiff = tickDiff / CLOCKS_PER_SEC;
    cout << "Clock count: " << tickDiff << "\tTime: " << clockDiff << endl;
    return 0;
}
