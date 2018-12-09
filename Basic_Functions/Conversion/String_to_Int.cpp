#include <iostream>
#include <string>
using namespace std;

int main()
	{
	string toConv;
	getline(cin, toConv);
	
	auto Conv = stoi(toConv,nullptr,10);
	cout << Conv << endl;

	char release;
	cin >> release;
	return 0;
	}