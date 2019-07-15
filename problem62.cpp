#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
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


int appender(string word, vector<int> &pointers)
{
    if (word.substr(pointers.at(0), 1) == "0")
    {
        return -1;
    }
	string newOrder = "";
	for (unsigned int i = 0; i < pointers.size(); i++)
	{
		newOrder.append(word.substr((pointers.at(i)), 1));
	}
	//cout << newOrder << endl;
    double newInt = stod(newOrder), throwAway, toKeep;
    toKeep = newInt;
    newInt = round(10000*cbrt(newInt))/10000;
    if (modf(newInt, &throwAway) == 0 && pow(throwAway,3) == toKeep)
    {
        //cout << "passed as: " << toKeep << " -> " << newInt << "\t" << endl;
        return (int)throwAway;
    }
    return -1;
}


int permuter(string word)
{
	vector<int> pointers;
    vector<int> cubeRoots;
    int firstPush = round(10000*cbrt(stod(word)))/10000;
    cubeRoots.push_back(firstPush);
    int length = word.size();

	//fills the array defined above
	for (int i = 0; i < length; i++)
	{
		pointers.push_back(i);
	}
	
	unsigned int swapper = 0, initial_comp = 0, rearrange = 0, asc_swapper = 0, count = 1;
	
	
	//cout << "Count: " << count << "\t";
    //cout << "repeating for: " << factorial(length) << endl;
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

        int checker = appender(word, pointers);
		if(checker != -1)
        {
            bool toPush = true;
            for (unsigned int i = 0; i < cubeRoots.size(); i++)
            {
                if (cubeRoots.at(i) == checker)
                {
                    toPush = false;
                    break;
                }
            }
            if (toPush)
            {
                cubeRoots.push_back(checker);
            }
        }
    }
    //cout << cubeRoots.size() << " cubes" << endl;
    if (cubeRoots.size() > 2)
    {
        for (unsigned int i = 0; i < cubeRoots.size(); i++)
        {
            cout << cubeRoots.at(i) <<"("<<pow(cubeRoots.at(i),3)<<"), ";
        }
        cout << endl;
    }
    return cubeRoots.size();
}


int main()
{
    double cube = 300;
    bool solved = false;
    while (!solved)
    {
        int power = round(pow(cube, 3));
        string str = to_string(power);
        //cout << "string: " << str << endl;
        
        int cubePerm = permuter(str);
        if (cubePerm > 2)
        {
            cout << "start cube: " << cube << "\tcubes: " << cubePerm << endl;
            if (cubePerm > 4)
            {
            solved = true;
            }
        }
        cube++;
    }
    return 0;
}
