#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> list;
    for (int i = 1; i < 7; i++)
    {
        list.push_back(i);
        cout << i << ", ";
    }
    cout << endl << list.size() << endl;

    for (int i = 1; i < list.size(); i++)
    {
        for (int j = 0; j < list.size()-i; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                cout << list.at(j+k) << ", ";
            }
            cout << endl;
        }
    }

    return 0;
}

