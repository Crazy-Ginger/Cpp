#include <math.h>
#include <iostream>
using namespace std;

 int main()
	{
	float temp;
	for (int i = 1; i<= 1000; i++)
		{
		temp =sqrt(i);
		cout << "i: " << i << "\t result: " << temp << endl;
		}
	
	
	char release;
	cin >> release;
	return 0;
	}