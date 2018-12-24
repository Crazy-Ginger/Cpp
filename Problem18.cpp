#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	char release;
	vector<vector<int>> triangle(0);
	vector<int> rows(0);
	fstream file;

	file.open("Euler_Files/Problem18_test.txt");
	triangle.clear();

	string str_line, str_numb;
	int int_temp;

	if (file.is_open())
	{
		while (getline(file, str_line))
		{
			for (char c : str_line)
			{
				if (c == ',' || c == '.')
				{
					istringstream convert(str_numb);

					if (!(convert >> int_temp))
						cout << "Error in converstion\n";

					rows.push_back(int_temp);
					str_numb.clear();
				}
				else
				{
					str_numb += c;
				}
			}
			triangle.push_back(rows);
			rows.clear();
			str_line.clear();
			str_numb.clear();
		}
	}
	

	vector <vector<int>> summed(triangle);

	for (int i = 0; i < triangle.size(); i++) //outputs the entire matrix in a formatted fashion
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j] << ", ";
			summed[i][j] = 1000;
        }
        cout << endl;
    }
	
	for (int y = 0; y < summed.size()-1; y++)	//tries to find the sum of all the possible paths
    {
        for (int x = 0; x < summed[y].size()-1; x++)
        {
			if (summed[y+1][x] > summed[y][x]+triangle[y+1][x])
			{
				summed[y+1][x] = summed[y][x] + triangle[y+1][x];
			}
			summed[y+1][x+1] = summed[y][x] + triangle[y+1][x+1];
			cout << summed[y][x] + triangle[y+1][x] << "\t" << summed[y][x] + triangle[y+1][x+1] << endl;
        }
        cout << endl;
    }

	cout << "\nSummed: \n";
	for (int i = 0; i < summed.size(); i++) //outputs summed
    {
        for (int j = 0; j < summed[i].size(); j++)
        {
            cout << summed[i][j] << ", ";

        }
        cout << endl;
    }
	
	for (int y = 0; y < summed.size()-1; y++)	//finding the smallest value at the bottom of summed
    {
        for (int x = 0; x < summed[y].size()-1; x++)
        {
			if (summed[y+1][x] > summed[y][x]+triangle[y+1][x])
			{
				summed[y+1][x] = summed[y][x] + triangle[y+1][x];
			}
			summed[y+1][x+1] = summed[y][x] + triangle[y+1][x+1];
        }
        cout << endl;
    }

	cout << "Finding the smallest\n";
	int_temp = 483646;
	for (int i = 0; i > summed[summed.size()].size(); i++)
	{
		cout << summed.at(summed.size()-1).at(i) << endl;
		/* if (summed[summed.size()-1][i] < int_temp)
		{
			int_temp = summed[summed.size()-1][i];
		} */
	}
	cout << int_temp << " Done\n";
	cin >> release;
	return 0;
}