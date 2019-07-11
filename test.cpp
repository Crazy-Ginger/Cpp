#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> list = {1487, 1847, 4817, 8147};
    int diff, lastDiff = 0;
    for (unsigned int i = 0; i < list.size()-1; i++)
    {
        lastDiff = 0;
        cout << "i: " << i  << endl;
        for (unsigned int j = i+1; j < list.size(); j++)
        {
            diff = list.at(j) - list.at(i);
            if (diff == lastDiff*2)
            {
                cout << "at i: " << list.at(i) << "\t" << list.at(j-1) << "\t" << list.at(j) << endl;
            }
            cout << diff << endl;
            lastDiff = diff;
        }
    }

    return 0;
}

