#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> primeSieve(vector <int> initial)
{
    vector<int>::iterator start = initial.begin();
    vector<int>::iterator end = initial.end();
    if (start == end)
    {
        cout << "No numbers\n";
    }
    else
    {
        //clear the container with 0
        fill(start, end, 0);
        //mark composites with 1
        for (vector<int>::iterator checker = start + 1; checker != end; ++checker)
        {
            if (*checker == 1)
            {
                continue;
            }
            //determine the prime number represented by this iterator location
            unsigned int stride = (checker - start) + 1;
            //mark all multiples of this prime number up to max
            vector<int>::iterator marker = checker;
            while ((end - marker) > stride)
            {
                advance(marker, stride);
                *marker = 1;
            }
        }

        //copy marked primes into container
        vector<int>::iterator out_it = start;
        for (vector<int>::iterator it = start + 1; it != end; ++it)
        {
            if (*it == 0)
            {
                *out_it = (it - start) + 1;
                ++out_it;
            }
        }
    }
    //removes the elements of the vector that doesn't contain primes
    vector<int>::iterator mark;
    for (mark = initial.begin(); mark != initial.end(); ++mark)
    {
            if (*mark == 1)
            {
                    initial.erase(mark, initial.end());
                    break;
            }
    }

    //checks for an error that allows 0 to be the last element in the array of vectors
    if (*(--initial.end()) == 0)
    {
            initial.erase(--initial.end());
    }

    return initial;
}


int main()
{


    return 0;
}
