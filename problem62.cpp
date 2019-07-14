#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


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

bool appender(string word, vector<int> &pointers)
{

	string newOrder = "";
	for (unsigned int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
	//cout << newOrder << endl;
    double newInt = stod(newOrder), throwAway;
    newInt = cbrt(newInt);
    if (modf(newInt, &throwAway) == 0)
    {
        cout << "passed appender as: " << newInt << endl;
        return true;
    }
    return false;
}

int permuter(string word)
{
	vector<int> pointers;
	int length = word.size(), cubes = 1;
	//fills the array defined above
	for (int i = 0; i < length; i++)
	{
		pointers.push_back(i);
	}
	
	unsigned int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;
	
	
	//cout << "Count: " << count << "\t";
	appender(word, pointers);

	for (count++; count <= factorial(length); ++count)
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


		if(appender(word, pointers))
        {
            cubes++;
            cout <<  cubes << " cubes" << endl;
        }
    }
    return cubes;
}


int main()
{
    char release;
    unsigned int cube = 2; 
    bool solved = false;
    while (!solved)
    {
        cout << "start cube: " << cube << endl;
        if (permuter(to_string(pow(cube, 3))) == 3)
        {
            solved = true;
        }
        cin >> release;
        cube++;

    }
    return 0;
}
