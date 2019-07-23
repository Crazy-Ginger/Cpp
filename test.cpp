#include <iostream>
#include <time.h>
#include <random>
using namespace std;

int main(int argc, char *argv[])
{
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution <> range(1, 10);
    for (int i = 0; i < 100; i++)
    {
        cout << range(rng) << endl;
    }
    return 1;
}

