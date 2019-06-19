#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <string> words;
    ifstream origList;
    origList.open("../../wordList.txt");
    if (!origList)
    {
        cerr << "Unable to open list\n";
    }
    string parser;
    while (origList >> parser)
    {
        transform(parser.begin(), parser.end(), parser.begin(), ::tolower);
        words.push_back(parser);

        parser.clear();
    }
    origList.close();
    
    ofstream newList ("../../wordListLower.txt");
    for (unsigned int i = 0; i < words.size(); i++)
    {
        cout << words.at(i) << endl;
        newList << words.at(i) << endl;
    }
    newList.close();
    return 0;
}
