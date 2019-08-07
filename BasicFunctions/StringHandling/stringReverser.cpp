#include <iostream>
#include <string>
using namespace std;

int main()
{
	string toRev;
	getline(cin, toRev);
	
	string Rev = "";
	for (int i = toRev.size(); i >= 0; i--)
		{
		Rev += toRev.substr(i,1);
		}
	cout << toRev << endl;
	cout << Rev << endl;
	char release;
	cin >> release;
	return 0;
}
