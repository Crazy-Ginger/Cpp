#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> primes(100000000);
vector <bool> primeCheck(100000001);


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


vector <int> primeFactorer(int numb)
{
    vector <int> factors;
    //iterates through the prime list to find prime factors 
    for (vector<int>::iterator i = primes.begin(); i!=primes.end(); i++)
    { 
        float remain = fmod(((float)numb),((float)*i));
        if (*i == numb)
        {
            factors.push_back(*i);
            break;
        }
        
        else if (remain == 0)
        {
            factors.push_back(*i);

            if (*i != numb)
            {
                vector <int> deeper = primeFactorer(numb/(*i));
                factors.insert(factors.begin(), deeper.begin(), deeper.end());
            }
            //break ensures that for loop stops after its found one primefacter at each level
            break;
        }
    }
    return factors;
}

bool primeProof(long checkL)
{
    string check = to_string(checkL);
    for (int i = check.size()-1; i >= -1; i--)
    {
        for (unsigned int j = 0; j < 10; j++)
        {
            string temp = check.substr(0, i);
            temp += to_string(j);
            temp += check.substr(i+1, check.size());
            if (temp.size() == check.size())
            {
                if (primeCheck.at(stoi(temp)))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    primes = primeSieve(primes);
    fill(primeCheck.begin(), primeCheck.end(),false);
    for(vector<int>::iterator i = primes.begin();i!=primes.end();i++)
    {
        primeCheck.at(*i) = true;
    }
    cout << "done the primes\n";

    vector <long> checkNums;
    for (unsigned int i = 0; i < 20000000; i++)
    {
        string base = to_string(i);
        for (int j = base.size(); j >= 0; j--)
        {
            string temp = base.substr(0, j);
            temp += "200";
            temp += base.substr(j, base.size());
            checkNums.push_back(stol(temp));
        }
    }
    sort(checkNums.begin(), checkNums.end());
    cout << "made numbers\n";


    for (unsigned int i = 0; i < checkNums.size(); i++)
    {
        if (primeProof(checkNums.at(i)))
        {
            vector <int> facs = primeFactorer(checkNums.at(i));
            if (facs.size() == 5)
            {
                if (facs.at(0) == facs.at(1)) 
                    {
                        if ((facs.at(2) == facs.at(3)) && (facs.at(4)==facs.at(3)))
                        {
                            cout << "found: " << checkNums.at(i) << endl;
                        }
                    }

                else if (facs.at(3) == facs.at(4))
                {
                    if ((facs.at(0) == facs.at(1)) && (facs.at(2)==facs.at(1)))
                    {
                        cout << "found: " << checkNums.at(i) << endl;
                    }
                }
            }
        }
    }
    return 0;
}
