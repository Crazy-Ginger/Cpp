#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

//created this to allow sorting strings by size
struct lenCompare 
{
    bool operator () (const string& first, const string& second)
    {
        return first.size() > second.size();
    }
};

//obtains a 2D list from a wordlist which contains the original word as well as a string of the chars sort alphabetically
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
    //the list of words to be returned
    vector <string> words;
    //duplicates so that the passed word isn't changed
    string temp = word;
    
    //iterates through the string and then if the string is longer than 1 recusively calls itself and adds the returned list to the list to be returned
    for (unsigned int i = 0; i < word.length(); i++)
    {
        //removes a character from the string and then adds it to the list
        temp.erase(temp.begin()+i);
        words.push_back(temp);

        //cheks if to call recusively
        if (temp.length() > 1)
        {
            vector <string> deeper = charless(temp);
            words.insert(words.end(), deeper.begin(), deeper.end());
        }
        
        //sets temp to word again so that the process can be repeated
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
    
    //sorts the word into alphabetical order
    sort(word.begin(), word.end());
    cout << "Sorted: " << word << endl;
    //gets a 2D vector with words and they're sorted form
    vector <vector <string>> dictionary = listGet(word.length());
    cout << "Got dictionary: " << dictionary.size() << "\n";

    //gets a vector of all possible words from the main word
    vector <string> anagrams = charless(word);
    //creates a new list of anagrams that won't contain duplicates
    vector <string> redAnagrams;
    //adds the original word to the redAnagrams
    redAnagrams.push_back(word);

    bool add = true;
    string adder;

    cout << "fullAnagrams: " << anagrams.size() << endl;
    //iterates through the full list and adds new unique ones to the reduced list
    for (vector<string>::iterator i=anagrams.begin(); i!=anagrams.end(); i++)
    {
        add = true;
        adder = *i;
        //checks the word being added isn't already in there
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
    
    //removes the content from the vector and shrinks it so it can be reused as the solution list to save mem
    anagrams.clear();
    anagrams.shrink_to_fit();
    cout << "reduced Anagrams: " << redAnagrams.size() << endl;
    
    cout << "\nSolutions: \n";
    
    //goes through the dictionary list and the anagrams list and looks for matching words and then adds them as solutions
    for (vector<string>::iterator i=redAnagrams.begin(); i!=redAnagrams.end(); i++)
    {
        for (unsigned int j = 0; j< dictionary.size(); j++)
        {
            if (*i == dictionary.at(j).at(1))
            {
                anagrams.push_back(dictionary.at(j).at(0));
            }
        }
    }

    //removes redAnagrams from mem
    vector<string>().swap(redAnagrams);
    //instantiates the sorting struct
    lenCompare comp;
    //sorts the solutions by length order (long->short)
    sort(anagrams.begin(), anagrams.end(), comp);
    //prints to console line
    for (vector<string>::iterator i = anagrams.begin(); i!=anagrams.end(); i++)
    {
        cout << *i << endl;
    }
}
