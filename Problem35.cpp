#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <string>
using namespace std;

//returns a vector of primes when called
template <typename ForwardIterator> size_t prime_sieve(ForwardIterator start, ForwardIterator end)
	{
	if (start == end) return 0;
	//clear the container with 0
	fill(start, end, 0);
	//mark composites with 1
	for (ForwardIterator prime_it = start + 1; prime_it != end; ++prime_it)
		{
		if (*prime_it == 1) continue;
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

bool rotator(int prime, vector <int> primes)
{

}

int main()
{
	char release;
	int panPrimes = 1;

	vector <int> primes(1000000);


	clock_t clock_start, clock_end;
	clock_start = clock();
	
	//returns the number of primes found as well as editting the ++
	size_t count = prime_sieve(primes.begin(), primes.end());
	
	//calculates time to mark all the primes
	clock_end = clock();
	float diff ((float)clock_end-(float)clock_start), seconds = diff/CLOCKS_PER_SEC;
	
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