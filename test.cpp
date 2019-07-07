#include <iostream>
#include <string>
#include <vector>
using namespace std;

unsigned int fact(int numb)
{
    if (numb >1)
    {
        return numb * fact(numb-1);
    }
    else
    {
        return 1;
    }
}
void printer(string word, vector<int> pointers)
{
    string newWord = "";
    for (vector<int>::iterator i = pointers.begin(); i != pointers.end(); i++)
    {
        newWord.append(word.substr(*i, 1));
    }
    cout << newWord << endl;
}

int main()
{
    string word;
    getline(cin, word);
    vector <int> pointers;
    unsigned int length = word.size();
    
    for (unsigned int i = 0; i < length; i++)
    {
        pointers.push_back(i);
        cout << i;
    }
    cout << endl;

    vector<int>::iterator initial_comp, rearrange, asc_swapper;
    unsigned int count = 1;
    cout << "Count: " << count << "\t";
    printer(word, pointers);
    count++;
    while (count <= fact(length))
    {
        initial_comp = pointers.end()-2;
        while (*initial_comp > 0)
        {
            if (*initial_comp < *(initial_comp+1))
            {
                break;
            }
            else
            {
                initial_comp--;
            }
        }
        rearrange = initial_comp + 1;
        asc_swapper = pointers.end();
            
        //arranges all the numbers after initial_comp into ascending order
        while (rearrange < asc_swapper)
        {
            unsigned int swapper = *rearrange;
            *rearrange = *asc_swapper;
            *asc_swapper = swapper;
            rearrange++;
            asc_swapper--;
        }
        rearrange = pointers.end();
       
        //finds the the largest number at the back so that it can be swapped
        while (*rearrange > *initial_comp)
        {
            rearrange--;
        }
    
        //swaps the largest number at the back of pointers with the number just infront of it
        rearrange++;
        unsigned int swapper = *initial_comp;
        *initial_comp = *rearrange;
        *rearrange = swapper;

        cout << "Count: " << count << "\t";
        printer(word, pointers);
        count++;
    }
    return 0;
}
