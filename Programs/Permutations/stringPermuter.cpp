#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

//used to allow for the length of permutations to be calculated
unsigned int factorial(int numb)
{
	if (numb > 1)
	{
		return numb * factorial(numb - 1);
	}
	else
	{
		return 1;
	}
}

//allows for the permutations to be recommbined using the pointers
void appender(string word, vector<int> &pointers)
{
	string newOrder = "";
	for (unsigned int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
	cout << newOrder << endl;
}

//generates the permutations of pointers and which can be passed to other functions
void Permuter(string word)
{
	vector<int> pointers;
	int length = word.size();

	//fills the array defined above
	for (int i = 0; i < length; i++)
	{
		pointers.push_back(i);
	}
	
    //variable declarations mainly for swapping the values in the array around and for counting the number of permutations
	unsigned int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;
	
	appender(word, pointers);

	while (count < factorial(length))
	{
		initial_comp = length - 2;

        while (pointers.at(initial_comp) > 0)
        {
            if (pointers.at(initial_comp) < pointers.at(initial_comp+1))
            {
                break;
            }
            else
            {
                initial_comp--;
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
		

		//selects the numbers the need to be swapped
        rearrange = length - 1;
		while (pointers.at(rearrange) > pointers.at(initial_comp))
		{
			rearrange--;
		}

		//swaps the largest number at the back with the number in fron of it
		rearrange++;
		swapper = pointers.at(initial_comp);
		pointers.at(initial_comp) = pointers.at(rearrange);
		pointers.at(rearrange) = swapper;

		appender(word, pointers);
        count++;

	}
    cout << "Final count: " << count << endl;
}


int main(int argc, char* argv[])
{
	//char release;
	string word = argv[1];
    cout << "Word: " << word << endl;
    
    clock_t start, end;
    start = clock();

	Permuter(word);
    
    end = clock();
    float tickDiff((float)end - float(start));
    float clockDiff = tickDiff / CLOCKS_PER_SEC;
    
    cout << "Clock cout: " << tickDiff << "\tTime: " << clockDiff <<endl;
	//cin >> release;
	return 1;
}
