#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <bool> primeCheck(10001);

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

unsigned int factorial(int numb)
{
	if (numb > 1)
	{
		return numb * factorial(numb - 1);
	}
	else
	{
		return 1;
	}
}

int appender(string word, vector<int> &pointers)
{

	string newOrder = "";
	for (unsigned int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
    return stoi(newOrder);
}

vector <int> Permuter(string word)
{
    vector <int> perPrimes;
    perPrimes.push_back(stoi(word));
	vector<int> pointers;
	int length = word.size();

	for (int i = 0; i < length; i++)
	{
		pointers.push_back(i);
	}
	
	unsigned int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;

	for (count++; count <= factorial(length); ++count)
	{
		initial_comp = length - 2;

        while (pointers.at(initial_comp) > 0)
        {
            if (pointers.at(initial_comp) < pointers.at(initial_comp+1))
            {
                break;
            }
            else
            {
                initial_comp--;
            }
        }

		rearrange = initial_comp + 1;
		asc_swapper = length - 1;

		while (rearrange < asc_swapper)
		{
			swapper = pointers.at(rearrange);
			pointers.at(rearrange) = pointers.at(asc_swapper);
			pointers.at(asc_swapper) = swapper;
			rearrange++;
			asc_swapper--;
		}
		rearrange = length - 1;

		while (pointers.at(rearrange) > pointers.at(initial_comp))
		{
			rearrange--;
		}

		rearrange++;
		swapper = pointers.at(initial_comp);
		pointers.at(initial_comp) = pointers.at(rearrange);
		pointers.at(rearrange) = swapper;
        
        int temp = appender(word, pointers);
		if (primeCheck.at(temp))
        {
            perPrimes.push_back(temp);
        }

	}
    return perPrimes;
}


int main()
{
    vector <int> primes(10000);
    primes = primeSieve(primes);

    fill(primeCheck.begin(), primeCheck.end(), false);
    for (vector<int>::iterator mark=primes.begin();mark!=primes.end();mark++)
    {
        primeCheck.at(*mark) = true;
    }
    
    vector<vector<int>> perPrimes;
    for (vector<int>::iterator i = primes.begin(); i!=primes.end();i++)
    {
        vector <int> temp = Permuter(to_string(*i));
        //cout << *i << ": " << temp.size() << endl;
        if (temp.at(0) >= 1000)
        {
            perPrimes.push_back(temp);
        }
    }
    cout << "numb of primePers: " << perPrimes.size() << endl;

    for (unsigned int i = 0; i < perPrimes.size(); i++)
    {
        for (unsigned int j =0; j < perPrimes.at(i).size(); j++)
        {
        }
    }
    return 0;
}
