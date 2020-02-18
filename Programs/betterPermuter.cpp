#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

void print(int ints[])
{
    int length = (sizeof(ints)/sizeof(*ints));
    for (int i = 0; i < length; i++)
    {
        cout << ints[i] << "\t";
    }
    cout << "\n";
}


int main(int argc, char* argv[])
{
    clock_t sClock, eClock;
    int ints[stoi(argv[1])];
    for (int i = 1; i <= (sizeof(ints)/sizeof(*ints)); i++)
    {
        ints[i] = i;
    }

    bool ext = false;
    sClock = clock();
    int edge;
    while (!ext)
    {
        ext = true;
        for (int i = stoi(argv[1])-1; i > 1; i--)
        {
            if (ints[i-1] > ints[i])
            {
                ext = false;
                edge = i-1;
            }
        }
        int rearrange = ext + 1;

        for (int i = stoi(argv[1])-1; i > rearrange; i--)
        {
            int swapper = ints[i];
            ints[i] = ints[rearrange];
            ints[rearrange] = swapper;
            rearrange ++;
        }
        int swapper = ints[ext];
        ints[ext] = ints[ext+1];
        ints[ext] = swapper;

        print(ints);
    }
    eClock = clock();
    double tickDiff = (float)eClock - (float)sClock;
    double clockDiff = tickDiff / CLOCKS_PER_SEC;
    cout << "Ticks: " << tickDiff << "\tTime: " << clockDiff << endl;
    return 0;
}
