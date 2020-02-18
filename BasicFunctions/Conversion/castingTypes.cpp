#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
	{
	vector <char> char_num = {1,2,3,4,5,6,7,8,9,10};
	vector <int> int_num;
	for (int i = 0; i < char_num.size(); i++)
		{
		int_num.push_back(static_cast<int>(char_num[i]));
		}
	for (int i = 0; i < int_num.size(); i++)
		{
		cout << int_num[i] << endl;
		}
	
	char release;
	cin >> release;	
	return 0;
	}