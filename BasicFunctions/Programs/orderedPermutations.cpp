#include <iostream>
using namespace std;


//prints the current permutation of the array in an easy to read manner
void print(int list[], int length)
{
	//cout << "Current permutation: ";
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << "\t" ;
	}
	cout << "\n";
}

int main()
{
	int length = 0;
	char release;
	cout << "How many numbers: ";
	cin >> length;
	cout << endl;
	int list[length];

	//fills the array defined above
	for (int i = 0; i < length; i++)
	{
		list[i] = i;
		//cout << "i: " << i << "\tlist[" << i << "]: " << list[i] << endl;
	}

	//last minute variable declarations mainly for swapping the values in the array around and for counting the number of permutations
	int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;
	bool last = false;


	//prints the first instance of the array
	//cout << "Count: " << count << endl;
	print(list, length);
	//cin >> release;

	

	do
	{
		count++;
		last = true;
		initial_comp = length - 2;
		for (initial_comp; initial_comp >= 0; initial_comp--)
		{
			//cout << "list[initial_comp]" << list[initial_comp] << endl;
			if (list[initial_comp] < list[initial_comp + 1])
			{
				last = false;
				break;
			}
		}
		rearrange = initial_comp + 1;
		asc_swapper = length - 1;

		while (rearrange < asc_swapper)
		{
			swapper = list[rearrange];
			list[rearrange] = list[asc_swapper];
			list[asc_swapper] = swapper;
			rearrange++;
			asc_swapper--;
		}
		rearrange = length - 1;

		//selects the numbers the need to be swapped
		while (list[rearrange] > list[initial_comp])
		{
			rearrange--;
		}

		//swaps the largest number at the back with the number in fron of it
		rearrange++;
		swapper = list[initial_comp];
		list[initial_comp] = list[rearrange];
		list[rearrange] = swapper;

		//cout << "Count: " << count << endl;
		//print(list,length);
		//cout << endl;

		
		if (!last)
		{
			//cout << "Count: " << count << endl;
			print(list, length);
			//cin >> release;
		}
		
	} while (!last); //ensures the do keeps going and only check at the end if it's the last permutation
	cout << endl << "Count: " << count-1 << endl;
	cin >> release;
	return 0;
}