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

//used to allow for the length of permutations to be calculated
int factorial(int numb)
{
	if (numb > 1)
	{
		return numb * factorial(numb - 1);
	}
	else
	{
		1;
	}
}

//allows for the permutations to be recommbined using the pointers
bool appender(string word, vector<int> &pointers, vector<bool> primeCheck)
{

	string newOrder = "";
	int checker;
	for (int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
	//needs to search through a bool for the primes and detect when the current prime has 2 other permutations then output those
	checker = stoi(newOrder);
	bool toPrint = false;
	if (checker == 1487 || checker == 4817 || checker == 8147)
	{
		toPrint = true;
	}
	if (primeCheck.at(checker))
	{
		if (toPrint)
		{
			cout << "Found " << checker << "and it outputted: " << true;
		}
		return true;
	}
	else
	{
		if (toPrint)
		{
			cout << "Found " << checker << "and it outputted: " << false;
		}
		return false;
	}
}

//generates the permutations of pointers and which can be passed to other functions
void Permuter(string word, vector<bool> primeCheck)
{
	vector<int> pointers;
	int length = word.size();

	int toOutput = 0;
	//fills the array defined above
	for (int i = 0; i < length + 1; i++)
	{
		pointers.push_back(i);
		//cout << "i: " << i << "\tlist[" << i << "]: " << pointers.at(i) << endl;
	}
	//cout << "filled vector\n";

	//variable declarations mainly for swapping the values in the array around and for counting the number of permutations
	int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;

	//cout << "Count: " << count << "\t";
	//appender(word, pointers, primeCheck);

	for (count++; count <= factorial(length); ++count)
	{
		initial_comp = length - 2;
		for (initial_comp; initial_comp >= 0; initial_comp--)
		{
			//cout << "list[initial_comp]" << list[initial_comp] << endl;
			if (pointers.at(initial_comp) < pointers.at(initial_comp + 1))
			{
				break;
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

		//selects the numbers the need to be swapped
		while (pointers.at(rearrange) > pointers.at(initial_comp))
		{
			rearrange--;
		}

		//swaps the largest number at the back with the number in fron of it
		rearrange++;
		swapper = pointers.at(initial_comp);
		pointers.at(initial_comp) = pointers.at(rearrange);
		pointers.at(rearrange) = swapper;

		//cout << "Count: " << count << endl;
		//print(list,length);
		//cout << endl;

		//cout << "Count: " << count << "\t";

		if (appender(word, pointers, primeCheck))
		{
			toOutput++;
		}

	} //ensures the do keeps going and only check at the end if it's the last permutation
	if (toOutput == 3)
	{
		cout << word << endl;
	}
	//cout << "\nPermuted!" << endl;
}

int main()
{
	char release;
	vector<int> primes(10000);
	primes = primeSieve(primes);

	//creates a more searchable vector for the primes
	vector<bool> primeCheck(10001);
	fill(primeCheck.begin(), primeCheck.end(), false);
	//marks all the primes in the bool vector which means that looking them up can be done much faster
	for (vector<int>::iterator mark = primes.begin(); mark != primes.end(); mark++)
	{
		primeCheck.at(*mark) = true;
	}
	for (vector<int>::iterator pointer = primes.begin(); pointer != primes.end(); pointer++)
	{
		Permuter(to_string(*pointer), primeCheck);
	}
	cin >> release;
}