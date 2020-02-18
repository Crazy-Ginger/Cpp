#include <iostream>

//for sleeping
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    for (int i = 10; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << "Lift off\n";
        }
        else if (i == 2)
        {
            cout << i << ": engine ignition\n";
        }
        else
        {
            cout << i << endl;
        }
        //seconds can be replaced with another time specifier
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}
