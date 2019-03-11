#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


void PrimeIt(vector <bool> &prime_v)
{
	fill(prime_v.begin(), prime_v.end(), true);
	
	for (long i = 2; prime_v.size() > i; i++)
	{
		if (prime_v.at(i) == false) continue;
		
		for (int a = 2; i*a < prime_v.size(); a++)
		{
			prime_v.at(i*a) = false;
		}
	}
}


int main()
	{
	char release;
	long choice;
	cin >> choice;
	vector <bool> primes(choice);
	int count = 0;
	
	clock_t clock_start, clock_end;
	clock_start = clock();
	
	PrimeIt(primes);
	
	clock_end = clock();
	float diff ((float)clock_end-(float)clock_start), seconds = diff/CLOCKS_PER_SEC;
	
	cout << "Primes\n";
	for (int i = 0; i < primes.size(); i++)
	{
		if (primes.at(i) == true && i!=0 && i!= 1)
		{
			//cout << i << "\t";
			count++;
		}
	}
	cout << "count: " << count;
	cout << "\nClock count: " << diff << "\tTime taken: " << seconds << endl;
	cin >> release;
	return 0;
}