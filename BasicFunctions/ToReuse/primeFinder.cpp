#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;


vector<int> primeSieve(vector <int> vect)
{
    vector<int>::iterator start = vect.begin();
    vector<int>::iterator end = vect.end();
    if (start == end)
    {
        cout << "No numbers\n";
    }
    else
    {
        //clear the container with 0
        fill(start, end, 0);
        //mark composites with 1 by finding primes and then multiplying them and marking the multiples
        for (vector<int>::iterator checker = start + 1; checker != end; ++checker)
        {
            if (*checker == 1)
            {
                continue;
            }
            //determine the prime number represented by this iterator location
            int stride = (checker - start) + 1;
            //mark all multiples of this prime number up to max
            vector<int>::iterator marker = checker;
            while ((end - marker) > stride)
            {
                //moves marker along the value of stride and assigns marker's value to 1
                advance(marker, stride);
                *marker = 1;
            }
        }

        //copy marked primes into container
        vector<int>::iterator out_it = start;
        for (vector<int>::iterator it = start + 1; it != end; ++it)
        {
            //finds the primes as they are marked with 0
            if (*it == 0)
            {
                //moves the primes towards the front of the list
                *out_it = (it - start) + 1;
                ++out_it;
            }
        }
    }

    //removes the elements of the vector that doesn't contain primes
    vector<int>::iterator mark;
    for (mark = vect.begin(); mark != vect.end(); ++mark)
    {
            if (*mark == 1)
            {
                    vect.erase(mark, vect.end());
                    break;
            }
    }

    //checks for an error that allows 0 to be the last element in the array of vectors
    if (*(--vect.end()) == 0)
    {
            vect.erase(--vect.end());
    }

    return vect;
}

int main(int argc, char* argv[])
{
    double choice = atof(argv[1]);
    vector<int> primes(choice);

    clock_t clock_start, clock_end;
    clock_start = clock();
    
    //uses a function call to set the vector filled with the primes
    primes = primeSieve(primes);

    //calculates time to mark all the primes
    clock_end = clock();
    float tickDiff((float)clock_end - (float)clock_start);
    float clockDiff = tickDiff / CLOCKS_PER_SEC;

    //creates a searchable vector for the primes
    vector<bool> primeCheck(choice + 1);
    fill(primeCheck.begin(), primeCheck.end(), false);
    //marks all the primes in the bool vector which means that looking them up can be done much faster
    for (vector<int>::iterator mark = primes.begin(); mark != primes.end(); mark++)
    {
        primeCheck.at(*mark) = true;
    }

    ////allows user to check if chosen numbers are prime
    //while (true)
    //{
        //cout << "Numb check: ";
        //cin >> choice;
        //cout << primeCheck.at((int)choice) << endl;
    //}

    ////display the primes
    for (size_t i = 0; i < primes.size(); ++i)
    {
        cout << "i: " << i+1 << "\t prime: " << primes[i] << endl;
    }

    cout << "Clock count: " << tickDiff << "\tTime taken: " << clockDiff << endl;
    cout << "Number of primes: " << primes.size() << endl;
    return 0;
}
