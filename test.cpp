#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> dupes;
    vector <int> unique;

    for (unsigned int i = 1; i < 5; i++)
    {
        cout << "Pushing back " << i << endl;
        for (unsigned int j = 0; j < i; j++)
        {
            dupes.push_back(i);
        }
    }

    //for (unsigned int i = 0; i < dupes.size(); i++)
    //{
        //cout << dupes.at(i) << endl;
    //}
    //cout << "done\n";
    
    bool push = false;
    unique.push_back(dupes.at(0));
    for (unsigned int i = 1; i < dupes.size(); i++)
    {
        push = true;
        for (unsigned int j = 0; j < unique.size(); j++)
        {
            if (dupes.at(i) == unique.at(j))
            {
                push = false;
            }
        }
        if (push)
        {
            unique.push_back(dupes.at(i));
        }
    }
    cout << "dupes: " << dupes.size() << "\tunique: " << unique.size() << endl;
    return 0;
}
