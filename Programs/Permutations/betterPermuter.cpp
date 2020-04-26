#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

void print(vector<unsigned int> ints)
{
    for (unsigned int i = 0; i < ints.size(); i++)
    {
        cout << ints.at(i) << "\t";
    }
    cout << "\n";
}


int main(int argc, char* argv[])
{
    clock_t sClock, eClock;

    vector<unsigned int> ints(stoi(argv[1]));
    
    for (unsigned int i = 0; i < ints.size(); i++)
    {
        ints.at(i) = i;
    }

    sClock = clock();
    bool escape = false;
    print(ints);
    while (!escape)
    {
        int edge = ints.size()-2;
        escape = true;
        for (edge; edge  >= 0; edge--)
        {
            if (ints.at(edge) < ints.at(edge+1))
            {
                escape = false;
                break;
            }
        }
        cout << "edge: " << edge << endl;
        unsigned int rearrange = edge + 1;

        for (unsigned int i = ints.size()-1; rearrange < i; i--)
        {
            unsigned int swapper = ints.at(i);
            ints.at(i) = ints.at(rearrange);
            ints.at(rearrange) = swapper;
            rearrange++;
        }

        unsigned int swapper = ints.at(edge);
        ints.at(edge) = ints.at(edge+1);
        ints.at(edge+1) = swapper;

        print(ints);
        cout << endl;
    }

    eClock = clock();
    double tickDiff = (float)eClock - (float)sClock;
    double clockDiff = tickDiff / CLOCKS_PER_SEC;
    cout << "Ticks: " << tickDiff << "\tTime: " << clockDiff << endl;
    return 0;
}
