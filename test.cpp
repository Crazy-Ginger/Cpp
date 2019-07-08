#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checker(string word)
{
    int primes[] = {2,3,5,7,11,13,17};
    for (unsigned int i = 1; (i+2) < word.length(); i++)
    {
        unsigned int current = stoi(word.substr(i, 3));
        if (current % primes[i-1] !=0)
        { 
            return false;
        }
    }
    cout << "Passed checkFor\n";
    return true;
}

int main()
{
    string word = "1406357289";
    cout << checker(word) << endl;
    return 0;
}
