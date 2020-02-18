#include <iostream>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
    if (argv[1])
    {
        cout << argv[1] << endl;
    }
    else
    {
        cout << "Nothing\n";
    }
    return 0;
}

