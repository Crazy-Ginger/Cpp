#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

vector <string> listGet(string list)
{
    vector <string> words;
    ifstream wordList;
    wordList.open(list);
    if (!wordList)
    {
        cerr << "Unable to open " << list << endl;
    }
    string parser;
    while (wordList >> parser)
    {
        transform(parser.begin(), parser.end(), parser.begin(), ::tolower);
        words.push_back(parser);
    }
    wordList.close();
    return words;
}

void fileWrite(string name, vector<string>list)
{
    ofstream writer;
    writer.open(name);
    if (writer.is_open())
    {
        for (vector<string>::iterator i=list.begin();i!=list.end();i++)
        {
            writer << *i << endl;
        }
    }
    writer.close();
}


int main(int argc, char* argv[])
{
    vector <string> words = listGet(argv[1]);
    sort(words.begin(), words.end());
   
    if (argc == 3)
    {
        fileWrite(argv[2], words);
    }
    else
    {
        fileWrite(argv[1], words);
    }
    return 0;
}
