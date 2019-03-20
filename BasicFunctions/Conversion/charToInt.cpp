#include <iostream>
using namespace std;

int main()
	{
	char release;
	char toConv;
	cin >> toConv;
	int conv = toConv - 64;
	cout << "toConv: " << toConv << "\tConv: " << conv << endl;
	
	cin >> release;
	return 0;
	}