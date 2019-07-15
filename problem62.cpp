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
    double newInt = stod(newOrder), throwAway, toKeep;
    toKeep = newInt;
    newInt = round(100000*cbrt(newInt))/100000;
    if (modf(newInt, &throwAway) == 0)
    {
        cout << "passed as: " << toKeep << " -> " << newInt << "\t";
        cout << endl;
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
    cout << "repeating for: " << factorial(length) << endl;
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
    double cube = 5; 
    bool solved = false;
    while (!solved)
    {
        int power = round(pow(cube, 3));
        cout << "start cube: " << cube << "\tcubed: " << power <<  endl;
        string str = to_string(power);
        cout << "string: " << str << endl;
        if (permuter(str) == 3)
        {
            solved = true;
        }
        cube++;

    }
    return 0;
}
