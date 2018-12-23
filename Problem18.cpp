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

	file.open("Euler_Files/Probkem18_triangle.txt");
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
			cout << "Converted a line and added it" << endl;
			rows.clear();
			str_line.clear();
			str_numb.clear();
		}

		cin >> release;
		return 0;
	}
}