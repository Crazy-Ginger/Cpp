#include <iostream>
#include <string>
using namespace std;

int main()
	{
	int toConv;
	cin >> toConv;
	
	auto Conv = to_string(toConv);
	cout << Conv << endl;
	
	char release;
	cin >> release;
	return 0;
	}