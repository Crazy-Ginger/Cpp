#include <iostream>
#include <vector>
#include <string>
using namespace std;

int size = 1000;
vector<bool>glbPrimes(size+1);


bool appender(string word, vector<int> &pointers)
{
	string newOrder = "";
	for (unsigned int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
	//cout << newOrder << endl;
    if (glbPrimes.at(stoi(newOrder)))
    {
        cout << newOrder << " passed" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Cycler(string word)
{
    vector<int> pointers;
    int length = word.size();

    for (int i = 0; i < length+1; i++)
    {
        pointers.push_back(i);
    }
    

}


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
        for (vector<int>::iterator prime_it = start + 1; prime_it != end; ++prime_it)
        {
            if (*prime_it == 1)
                continue;
            //determine the prime number represented by this iterator location
            int stride = (prime_it - start) + 1;
            //mark all multiples of this prime number up to max
            vector<int>::iterator mark_it = prime_it;
            while ((end - mark_it) > stride)
            {
                advance(mark_it, stride);
                *mark_it = 1;
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
    vector<int> intPrimes(size);
    intPrimes = primeSieve(intPrimes);
    fill(glbPrimes.begin(), glbPrimes.end(), false);

    for(vector<int>::iterator mark = intPrimes.begin(); mark!=intPrimes.end(); mark++)
    {
        glbPrimes.at(*mark) = true;
    }
    vector<int> cycPrimes;
    for (unsigned int i = 0; i < intPrimes.size(); i++)
    {
        cout << "First input: " << intPrimes.at(i) << endl;
        if (Cycler(to_string(intPrimes.at(i))))
        {
            cycPrimes.push_back(intPrimes.at(i));
            cout << intPrimes.at(i) << endl;
        }
        cout << endl;
    }
    cout << "Solutions: " << cycPrimes.size() << endl;
    return 1;
}

