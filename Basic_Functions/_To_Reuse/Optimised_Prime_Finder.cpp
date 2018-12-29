#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

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

int main()
{
	char release;
	double choice;
	//long long sum = 0; used to find the sum (no longer necessary)

	cin >> choice;
	vector<int> primes(choice);

	clock_t clock_start_old, clock_end_old, clock_start_new, clock_end_new;
	clock_start_old = clock();

	//there seems to be no noticeable difference between using a function and template (tested using 10,000,000)
	//size_t count = prime_sieve(primes.begin(), primes.end());	//uses the tried and tested template
	primes = primeSieve(primes);	//trying to use a function to find the primes instead of a templates

	//calculates time to mark all the primes
	clock_end_old = clock();
	float diff((float)clock_end_old - (float)clock_start_old), seconds = diff / CLOCKS_PER_SEC;


	//creates a more searchable vector for the primes
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
	if (choice < 1000000)
	{
		for (size_t i = 0; i < primes.size(); ++i)
		{
			cout << "i: " << i << "\t prime: " << primes[i] << endl;
		}
	}

	cout << "Clock count: " << diff << "\tTime taken: " << seconds << endl;
	//cout << "Number of primes: " << count << endl;

	//to escape the program
	cin >> release;
	return 0;
}