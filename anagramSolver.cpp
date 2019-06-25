#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct lenCompare 
{
    bool operator () (const string& first, const string& second)
    {
        return first.size() > second.size();
    }
};


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

vector <string> charless(string word )
{
    //char release;
    //cout << "\nCharless called again, word length: " << word.length() << endl;
    vector <string> words;
    string temp = word;
    //cout << "New less: " << word << endl;

    for (unsigned int i = 0; i < word.length(); i++)
    {
        temp.erase(temp.begin()+i);
        words.push_back(temp);
        if (temp.length() > 1)
        {
            vector <string> deeper = charless(temp);
            words.insert(words.end(), deeper.begin(), deeper.end());
        }
        else
        {
            words.push_back(temp);
        }
        //cout << temp << endl;
        temp = word;
    }
    //cin >> release;
    return words;
}

int main()
{
    cout << "Word: ";
    string word;
    //char release;
    getline(cin, word);
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    cout <<  endl;
    
    sort(word.begin(), word.end());
    cout << "Sorted: " << word << endl;
    vector <vector <string>> dictionary = listGet(word.length());
    cout << "Got dictionary: " << dictionary.size() << "\n";

    //charless(word);
    vector <string> fullanagrams = charless(word); 
    vector <string> redAnagrams;
    redAnagrams.push_back(word);
    bool add = true;
    string adder;


    cout << "fullAnagrams: " << fullanagrams.size() << endl;
    for (vector<string>::iterator i=fullanagrams.begin(); i!=fullanagrams.end(); i++)
    {
        add = true;
        adder = *i;
        for (vector<string>::iterator j=redAnagrams.begin(); j!=redAnagrams.end(); j++)
        {
            if (*i == *j)
            {
                add = false;
                break;
            }
        }
        if (add)
        {
            //cout << "Added: " << adder << endl;
            redAnagrams.push_back(adder);
        }
    }

    cout << "reduced Anagrams: " << redAnagrams.size() << endl;
    //for (vector<string>::iterator i=redAnagrams.begin(); i!=redAnagrams.end(); i++)
    //{
        //cout << *i << endl;
    //}
    vector<string> solutions;
    cout << "\nSolutions: \n";
    
    for (vector<string>::iterator i=redAnagrams.begin(); i!=redAnagrams.end(); i++)
    {
        for (unsigned int j = 0; j< dictionary.size(); j++)
        {
            if (*i == dictionary.at(j).at(1))
            {
                solutions.push_back(dictionary.at(j).at(0));
            }
        }
    }
    
    lenCompare comp;
    sort(solutions.begin(), solutions.end(), comp);
    for (vector<string>::iterator i = solutions.begin(); i!=solutions.end(); i++)
    {
        cout << *i << endl;
    }
}
