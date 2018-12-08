#include <string>
#include <iostream>
using namespace std;

int main()
{
    char release;

    string input;
    getline(cin, input);

    for (int i = 0; i < input.size(); i++)
	{
		cout << input.substr(i, 1) << endl;
	}
	cout << "done\n";
    cin >> release;
    return 0;
}