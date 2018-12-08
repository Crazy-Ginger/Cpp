#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	char release;
	long double big = 0;
	for (int i = 1; i < 100; i++)
	{
		
		for (int a = 1; a < 100; a++)
		{
			big += pow(i, a);
			
			if (big ==0)
		{
			cout<< "Hit a problem at: " << i << "\t" << a << endl;
			cin >> release;
		}
		}
		
		
		cout <<"Big: " <<  big << endl;
	}
	cout << big << endl;
	
	
	cin >> release;
	return 1;
}