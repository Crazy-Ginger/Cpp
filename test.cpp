#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    string firHalf = "";
    for (int i = 0; i < input.size()/2; i++)
    {
        firHalf += input.substr(i,1);
    }
    string lasHalf = "";
    for (int i = input.size(); i > input.size()/2; i--)
    {
        lasHalf += input.substr(i, 1);
    }
    if (lasHalf.size() < firHalf.size())
    {
        lasHalf += input.substr(input.size()/2, 1);
    }
    cout << "firHalf: " << firHalf << endl;
    cout << "lasHalf: " << lasHalf << endl;

    return 0;
}

