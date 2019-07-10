#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string word = "lengthhere";
    string lastChar = word.substr(word.length()-1, 1);
    cout << "word: " << word << "\tlastChar: " << lastChar << endl;
    return 0;
}
