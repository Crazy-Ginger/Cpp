#include <iostream>
#include <string>
using namespace std;

int main()
{
    char release;
    int input;
    cin >> input;

    string converted = to_string(input);

    for (int i = 0; i < converted.length(); i++)
    {
        if (stoi(converted.substr(i, 1), nullptr, 10) % 2 ==0)
		{
			cout << "found 2\n";
            break;
		}
    }
    
    cin >> release;
    return 0;
}