#include <iostream>
#include <string>
using namespace std;

int main()
{
    string block = "\u2588";
    cout << "\033[1;31mBold red text\033[0m\n";
    cout << "\033[1;31mThis should be " << block << "\033[0m\n";
    return 1;
}
