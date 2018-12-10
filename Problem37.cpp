#include <iostream>
#include <vector>
#include <string>
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

bool isPrime(int prime, vector<int> primes)
{
	for (vector<int>::iterator i = primes.begin(); i != primes.end(); ++i)
	{
		if (*i == prime)
		{
			return true;
		}
		else if(*i > prime)
		{
			return false;
		}
	}
	return false;
}
bool right(int Prime, vector<int> primes)
{
	auto str_Prime = to_string(Prime);
	for (int i = 1; i <= str_Prime.length(); i ++)
	{
		int temp = stoi(str_Prime.substr(str_Prime.length() - i), nullptr, 10);
		
		if (!isPrime(temp, primes))
		{
			return false;
		}
	}
	return true;
}


bool left(int Prime, vector<int> primes)
{
	auto str_Prime = to_string(Prime);
	for (int i = 1; i <= str_Prime.length(); i ++)
	{
		int temp = stoi(str_Prime.substr(0,i), nullptr, 10);
		
		if (!isPrime(temp, primes))
		{
			return false;
		}
	}
	return true;
}


int main()
{
    char release;
    vector <int> primes(1000000);

	size_t count = prime_sieve(primes.begin(), primes.end());

    vector<int>::iterator mark;
	for (mark = primes.begin(); mark != primes.end(); ++mark)
	{
		if (*mark == 1)
		{
			primes.erase(mark, primes.end());
			break;
		}
	}
	for (mark = primes.begin(); mark != primes.end(); ++mark)
	{
		if (*mark > 10)
		{	
			primes.erase(primes.begin(), mark);
			break;
		}
	}
	int sum = 0;
	int numb = 0;
	cout << "starting the sum\n";
	for (mark = primes.begin(); mark != primes.end(); ++mark)
	{
		if ((left(*mark, primes) && right(*mark, primes)) == true)
		{
			numb ++;
			cout << numb << ": " << *mark;
			sum += *mark;
			
		}
		if (numb == 11)
		{
			break;
		}
	}

    cin >> release;
    return 0;
}