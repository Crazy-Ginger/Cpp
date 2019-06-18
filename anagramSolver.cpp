#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

vector <vector<string>> listGet(unsigned int length)
{
    char release;
    vector <vector<string>> words;
    ifstream wordList;
    wordList.open("wordList.txt");
    if (!wordList)
    {
        cerr << "Unable to open wordList\n";
    }
    string parser;
    vector <string> adder;
    while (wordList >> parser)
    {
        if (parser.length() <= length)
        {
            transform(parser.begin(), parser.end(), parser.begin(), ::tolower);
            //cout << parser << "\t";
            adder.push_back(parser);
            sort(parser.begin(), parser.end());
            //cout << parser << endl;
            adder.push_back(parser);
            words.push_back(adder);
            
            //clear the variables
            adder.clear();
            parser.clear();

            //cin >> release;
        }
    }
    wordList.close();
    return words;
}

vector <string> oneCharLess(string word)
{
    vector <string> words;
    for (int i = 0; i < word.length(); i++)
    {
        words.push_back(word.substr(Lq

int main()
{
    string word;
    getline(cin, word);
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    cout << "Word: " << word << endl;
    
    sort(word.begin(), word.end());
    cout << "Sorted: " << word << endl;
    vector <vector <string>> dictionary = listGet(word.length());
    cout << "Got distionary\n\n";


    for (unsigned int i = 0; i < dictionary.size(); i++)
    {
        //cout << "Words: "; 
        for (unsigned int j = 0; j < dictionary.at(i).size(); j++)
        {
            cout << dictionary[i][j] << "\t";
        }
        cout << endl;
    }

}
