#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;


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



int main(int argc, const char* argv[])
	{
	char release;
	double choice;
	//long long sum = 0; used to find the sum (no longer necessary)
	
	cin >> choice;
	vector <int> primes(choice);
	
	clock_t clock_start, clock_end;
	clock_start = clock();
	
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
	
	//display the primes
	for (size_t i = 0; i < primes.size(); ++i)
		{
		cout <<"i: " << i << "\t prime: " << primes[i]<< endl;
		}
	
	cout << "Clock count: " << diff << "\tTime taken: " << seconds << endl;
	cout << "Number of primes: " << count << /*"\tSum: " << sum <<*/ endl;
	cin >> release;
	return 0;
}