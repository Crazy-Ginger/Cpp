#include <iostream>
#include <vector>
#include <string>
using namespace std;


int factorial(int numb)
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

bool checker(string word)
{
    
    return true;
}

string appender(string word, vector<int> &pointers)
{
	string newOrder = "";
	for (unsigned int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
	//cout << newOrder << endl;
    return newOrder;
}

vector<int> Permuter(string word)
{
    vector <int> toReturn;
	vector<int> pointers;
	int length = word.size();

	//fills the array defined above
	for (int i = 0; i < length + 1; i++)
	{
		pointers.push_back(i);
	}

	int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;
	

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

		cout << "Count: " << count << "\t";
        
        string newOrder = appender(word, pointers);

        if (checker(newOrder))
        {
            toReturn.push_back(stoi(newOrder));
        }

	}
    return toReturn;
}

int main()
{
    vector <int> numbs;
    numbs = Permuter(to_string(1234567890));
    return 0;
}
