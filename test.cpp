#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double input, throwAway, frac;
    cout << "input: ";
    cin >> input;
    cout << endl;
    cout << "cbrt(input): " << cbrt(input) << endl;

    cout << "is a cube?: ";
    input = cbrt(input);
    input = round(input*100000)/100000;

    if (modf(input, &throwAway) == 0)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}

