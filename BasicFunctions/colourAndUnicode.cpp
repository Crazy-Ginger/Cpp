#include <iostream>
#include <string>
using namespace std;

int main()
{
    string b = "\u03A3";
    cout << "\033[1;31mBold red text\033[0m\n";
    cout << "\033[1;31mThis should be " << b << "\033[0m\n";
    return 1;
}
