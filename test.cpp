#include <iostream>
#include <string>
#include <vector>
using namespace std;

void output(string word, vector<int> &pointers)
{
    string newOrder = "";
    for (unsigned int i = 0; i < pointers.size(); i++)
    {
        newOrder.append(word.substr(pointers.at(i), 1));
    }
    cout << newOrder << endl;
}


int main()
{
    string word =  "wordthis";
    vector <int> pointers;
    int length = word.size();

    for (int i = 0; i < length; i++)
    {
        pointers.push_back(i);
        cout << i << "\t" << word.substr(i, 1) << endl;
    }
    cout << endl;
    output(word, pointers);    
    for (int i = 1; i < length; i++)
    {
        for (vector<int>::iterator itter = pointers.begin(); itter!=pointers.end(); itter++)
            {
                *itter = (*itter+1)%length;
            }
        output(word, pointers);
    }
}
