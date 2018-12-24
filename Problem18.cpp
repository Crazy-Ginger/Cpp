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

	//Gets the triangle file and creates a vector that contains it
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

	//displays the triangle to check that it has been correctly copied from the txt file
	cout << "Triangle:\n";
	for (int i = 0; i < triangle.size(); i++) 
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j] << ", ";
        }
        cout << endl;
    }
	

	//tries to find the sum of all the possible paths
	for (int y = 0; y < summed.size()-1; y++)	
    {
        for (int x = 0; x < summed[y].size()-1; x++)
        {
			if (summed[y+1][x] < summed[y][x]+triangle[y+1][x])
			{
				summed[y+1][x] = summed[y][x] + triangle[y+1][x];
			}
			summed[y+1][x+1] = summed[y][x] + triangle[y+1][x+1];
        }
    }


	//outputs summed for checking
	cout << "\nSummed: \n";
	for (int i = 0; i < summed.size(); i++) 
    {
        for (int j = 0; j < summed[i].size(); j++)
        {
            cout << summed[i][j] << ", ";

        }
        cout << endl;
    }
	
	//finding the largest value at the bottom of summed
	for (int y = 0; y < summed.size()-1; y++)	
    {
        for (int x = 0; x < summed[y].size()-1; x++)
        {
			if (summed[y+1][x] < summed[y][x]+triangle[y+1][x])
			{
				summed[y+1][x] = summed[y][x] + triangle[y+1][x];
			}
			summed[y+1][x+1] = summed[y][x] + triangle[y+1][x+1];
        }
    }

	int_temp = 0;
	for (int i = 0; i < summed.size(); i++) 
    {
        for (int j = 0; j < summed[i].size(); j++)
        {
            //cout << summed[i][j] << ", ";
			if (summed[i][j] < int_temp)
			{
				int_temp = summed[i][j];
			}
        }
    }
	cout << "\n\n";
	cout << int_temp << " Done\n";
	cin >> release;
	return 0;
}