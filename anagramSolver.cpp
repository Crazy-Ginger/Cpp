#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

vector <vector<string>> listGet(unsigned int length)
{
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

vector <string> charless(string word, vector<string> anagrams)
{
    char release;
    cout << "\nCharless called again, word length: " << word.length() << endl;
    vector <string> words;
    string temp = word;
    //cout << "New less: " << word << endl;

    for (unsigned int i = 0; i < word.length(); i++)
    {
        temp.erase(temp.begin()+i);
        words.push_back(temp);
        if (temp.length() > 1)
        {
            vector <string> newana = charless(temp, newana);
            words.insert(words.end(), anagrams.begin(), anagrams.end());
            words.insert(words.end(), newana.begin(), newana.end());
        }
        else
        {
            words.insert(words.end(), anagrams.begin(), anagrams.end());
        }
        cout << temp << endl;
        temp = word;
    }
    cin >> release;
    return words;
}

int main()
{
    string word;
    char release;
    getline(cin, word);
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    cout << "Word: " << word << endl;
    
    sort(word.begin(), word.end());
    cout << "Sorted: " << word << endl;
    vector <vector <string>> dictionary = listGet(word.length());
    cout << "Got distionary: " << dictionary.size() << "\n\n";
    cin >> release;

    //charless(word);
    vector <string> anagrams;
    anagrams = charless(word, anagrams); 
    

}
