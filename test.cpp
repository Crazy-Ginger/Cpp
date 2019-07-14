#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string  i = "1000000000000";
    unsigned long long intI = stoull(i);
    cout << i << " became " << intI << endl;
    if (intI == 1000000000000)
    {
        cout << "true\n";
    }
    return 0;
}

