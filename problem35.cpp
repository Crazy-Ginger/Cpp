#include <iostream>
#include <vector>
#include <string>
using namespace std;

//finds all the primes and fills a vector with them
vector<int> primeSieve(vector<int> initial)
{
	vector<int>::iterator start = initial.begin();
	vector<int>::iterator end = initial.end();
	if (start == end)
	{
		cout << "No numbers\n";
		return vector<int>(0);
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
			size_t stride = (prime_it - start) + 1;
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
	return initial;
}


bool rotator(int prime, vector <int> primesCheck)
{
	auto strPrime =to_string(prime);
	vector<int> pointers();
	for (int i = 0; i < strPrime.length(); i++)
	{
		pointers.push_back(i);
	}

	
}


int main()
{
	char release;
	int panPrimes = 0;

	vector <int> primes(100);
	primes = primeSieve(primes);


	
	//returns the number of primes found as well as editting the ++
	size_t count = prime_sieve(primes.begin(), primes.end());
	
	//removes the elements of the vector that doesn't contain primes
	vector<int>::iterator mark;
	for (mark = primes.begin(); mark != primes.end(); ++mark)
	{
		if (*mark == 1)
		{
			primes.erase(mark, primes.end());
			break;
		}
	}
	
	for (vector<int>::iterator i = primes.begin(); i != primes.end(); ++i)
	{
		if (rotator(*i, primes))
		{	
			cout << "pan prime: " << *i << endl;
			panPrimes++;
		}
	}

	//cout << "Clock count: " << diff << "\tTime taken: " << seconds << endl;
	cout << "Number of primes: " << count << endl;
	cout << "Panprimes: " << panPrimes << endl;

	cin >> release;
	return 0;
}