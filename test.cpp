#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    double i = 3;
    double temp = pow(i, 5), throwAway;
    temp = cbrt(temp);
    cout << temp << "\trooted: " << temp << endl;
    cout << "modf: " << modf(temp, &throwAway) << endl;
    return 0;
}

