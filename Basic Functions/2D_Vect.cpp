#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int row;
	cout << "Number of rows: "; cin >> row; cout << endl;
	
	int column;
	cout << "Number of columns: "; cin >> column; cout << endl;
 	
	// Create a vector of vector with size equal to row.
	vector <vector<int>> vec(row); 
	int increment = 1;
	for (int i = 0; i < row; i++)
		{
		vec[i] = vector <int>(column);
		for (int j = 0; j < column; j++)
			{
			vec[i][j] = increment;
			increment ++;
			}
		}
	
	for (int i = 0; i < column; i++)
		{
		cout << i << "\t";
		}
	cout << endl;
	for (int i = 0; i < row; i++) 
		{
		for (int j = 0; j < vec[i].size(); j++)
			{
			cout << vec[i][j] << "\t";
			}
		cout << endl;
		}
	
	char release;
	cin >> release;
}
