#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

vector<string> listGet(unsigned int length)
{
    vector <string> words;
    ifstream wordList;
    wordList.open("wordList.txt");
    if (!wordList)
    {
        cerr << "Unable to open wordList\n";
    }
    string parser;
    while (wordList >> parser)
    {
        if (parser.length() <= length)
        {
            transform(parser.begin(), parser.end(), parser.begin(), ::tolower);
            words.push_back(parser);
        }
    }
    wordList.close();
    return words;
}


int main()
{
    string word;
    getline(cin, word);
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    cout << "Word: " << word << endl;
    
    sort(word.begin(), word.end());
    cout << "Sorted: " << word << endl;
    vector <string> dictionary = listGet(word.length());

}
