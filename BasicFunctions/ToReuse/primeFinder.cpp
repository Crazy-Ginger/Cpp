#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;


/*
template <typename ForwardIterator>
size_t prime_sieve(ForwardIterator start, ForwardIterator end)
{
	if (start == end)
		return 0;
	//clear the container with 0
	fill(start, end, 0);
	//mark composites with 1
	for (ForwardIterator prime_it = start + 1; prime_it != end; ++prime_it)
	{
		if (*prime_it == 1)
			continue;
		//determine the prime number represented by this iterator location
		size_t stride = (prime_it - start) + 1;
		//mark all multiples of this prime number up to max
		ForwardIterator mark_it = prime_it;
		while ((end - mark_it) > stride)
		{
			advance(mark_it, stride);
			*mark_it = 1;
		}
	}

	//copy marked primes into container
	ForwardIterator out_it = start;
	for (ForwardIterator it = start + 1; it != end; ++it)
	{
		if (*it == 0)
		{
			*out_it = (it - start) + 1;
			++out_it;
		}
	}
	return out_it - start;
}*/

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

	//checks for an error that allows 0 to be the last element in the array of vectors
	if (*(--initial.end()) == 0)
	{
		initial.erase(--initial.end());
	}

	return initial;
}

int main()
{
	char release;
	double choice;

	cin >> choice;
	vector<int> primes(choice);

	clock_t clock_start, clock_end;
	clock_start = clock();

	//there seems to be no noticeable difference between using a function and template (tested using 10,000,000)
	//size_t count = prime_sieve(primes.begin(), primes.end());	//uses the tried and tested template, this returns an integer and accesses the values using pointers
	primes = primeSieve(primes);	//using the function as there is no noticeable time difference and it returns a vector rather than an integer

	//calculates time to mark all the primes
	clock_end = clock();
	float tickDiff((float)clock_end - (float)clock_start), clockDiff = tickDiff / CLOCKS_PER_SEC;

	//creates a searchable vector for the primes
	vector<bool> primeCheck(choice + 1);
	fill(primeCheck.begin(), primeCheck.end(), false);
	//marks all the primes in the bool vector which means that looking them up can be done much faster
	for (vector<int>::iterator mark = primes.begin(); mark != primes.end(); mark++)
	{
		primeCheck.at(*mark) = true;
	}


	/* //removes the elements of the vector that doesn't contain primes (not neccessary when using the function as this is built in)
	vector<int>::iterator mark;
	for (mark = primes.begin(); mark != primes.end(); ++mark)
	{
		if (*mark == 1)
		{
			primes.erase(mark, primes.end());
			break;
		}
	} */

	//display the primes
	for (size_t i = 0; i < primes.size(); ++i)
	{
		cout << "i: " << i << "\t prime: " << primes[i] << endl;
	}

	cout << "Clock count: " << tickDiff << "\tTime taken: " << clockDiff << endl;
	cout << "Number of primes: " << primes.size() << endl;

	//to escape the program
	//cin >> release;
	return 0;
}
