#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{
    char release;
    vector<vector<vector<string>>> box;
    
    for (int y = 0; y < 6; y++)
    {
        vector<vector<string>> twoDPusher;
        for (int z = 0; z < 6; z++)
        {
            vector <string> oneDPusher;
            for (int x = 0; x < 6; x++)
            {
                oneDPusher.push_back(to_string(x+y+z));
            }
            twoDPusher.push_back(oneDPusher);
        }
        box.push_back(twoDPusher);
    }
    for (unsigned int y=0; y<box.size(); y++)
    {
        for (unsigned int z=0; z<box.at(y).size(); z++)
        {
            for (unsigned int x=0; x<box.at(y).at(z).size(); x++)
            {
                cout << box.at(y).at(z).at(x) << ",\t";
            }
            cout << endl;
        }
        cin >> release;
        cout << endl << endl << endl;
    }

    return 0;
}
