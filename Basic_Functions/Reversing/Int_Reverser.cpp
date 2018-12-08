#include <iostream>
#include <string>
using namespace std;

int main()
	{
	int toRev;
	cin >> toRev;
	
	auto toRevCon = to_string(toRev);
	string Rev;

	for (int i = toRevCon.size(); i >= 0; i--)
		{
		Rev += toRevCon.substr(i,1);
		}
	cout << toRev << endl;
	cout << Rev << endl;
	char release;
	cin >> release;
	return 0;
	}