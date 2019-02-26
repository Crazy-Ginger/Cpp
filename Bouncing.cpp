#include <iostream>
#include <vector>
using namespace std;

class particle
{
	
};

class table
{
  private:
	vector<vector<char>> grid;
	int dimx;
	int dimy;

	void set_grid()
	{
		vector <char> row;
		for (int y = 0; y <= dimy; y++)
		{
			for (int x = 0; x <= dimx; x++)
			{
				if (y == 0 || y == dimy)
				{
					row.push_back('-');
				}
				else if (x == 0 || x == dimx)
				{
					row.push_back('|');
				}
				else
				{
					row.push_back(static_cast<char>(' '));
				}

				//cout << static_cast<char>(x) << ", ";
			}
			grid.push_back(row);
			row.clear();
		}
	}

  public:
	void display()
	{
		for (int y = 0; y <= dimy; y++)
		{
			cout << y << " ";
			for (int x = 0; x <= dimx; x++)
			{
				cout << grid.at(y).at(x) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void set_dim(int x = 10, int y = 10)
	{
		dimx = x;
		dimy = y;
		set_grid();
	}
};


int main()
{
	table current;
	int x , y;

	cout << "Width: ";
	cin >> x;
	cout << "Height: ";
	cin >> y;
	cout << endl;
	current.set_dim(x, y);
	current.display();

	return 0;
}
