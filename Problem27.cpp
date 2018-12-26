#include <iostream>
#include <vector>
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

//returns the number of consecutive primes
int algorithm(int a, int b, vector<int> primes)
{
	vector<int>::iterator pointer = primes.begin();
	for (vector<int>::iterator checker = primes.begin(); checker != primes.end(); checker++)
	{
		if (*checker = b)
		{
			pointer = checker;
			break;
		}
	}

	int length = 0;
	int n = 0;
	while (true)
	{
		int next = (n*n + a*n + b);
		if (*pointer != next)
		{
			return length;
		}
		n++;
		length++;
		pointer++;
	}
	return length;
}


int main()
{
	char release;
	int coefficienta, coefficientb;
	int longest = 0, length;
	vector <int> primes(10000000);
	size_t count = prime_sieve(primes.begin(), primes.end());

	for (int a = -1000; a < 1000; a ++)
	{
		cout << "a: " << a << endl;
		for (vector<int>::iterator b = primes.begin(); *b < 1000; b++)
		{
			/* cout << "\tb: " << *b << endl; */
			length = algorithm(a, *b, primes);
			/* if (length > 35)
			{
				cout << "length: " << length << "a & b: " << a << " " << *b << endl;
			} */
			if (length > longest)
			{
				coefficienta = a;
				coefficientb = *b;
				longest = length;
			}
		}
	}
	cout << "Answers: " << coefficienta << ", " << coefficientb << "\tTherefore the product is: " << coefficientb*coefficienta <<  endl;
	cout << "With length: " << longest << endl;
	cin >> release;
}