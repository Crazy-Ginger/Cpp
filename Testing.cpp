#include <iostream>
//#include <vector>
//#include <stdlib.h>
#include <windows.h>    //required for "SetConsoleTextAttribute"
using namespace std;

int main()
{
    char release;

    //handles changing the colour of the text in the output
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //needs to be defined at the beginning unsure what it does right now

    SetConsoleTextAttribute(color, 10); //example of setting the text colour of the console so that it only affects the text written at the time
    cout << "Random humbugs eating an apple a day\n";
    SetConsoleTextAttribute(color, 4);
    cout << "Random humbugs eating an apple a day\n";
    

    
    /* int size;   //testing errors when trying to read values outside on an array (returns an error)
    cin >> size;
    vector <int> tiny(size);
    fill (tiny.begin(), tiny.end(), 2);
    cout << tiny.at(6); */


    /*  vector<bool> test(80);
    fill(test.begin(), test.end(), true);

    int sumTrue = 0;
    for (int i = 0; i < test.size(); i++)
    {
        if (test[i])
        {
            sumTrue++;
        }
    }
    cout << sumTrue << "\t" << test.size() << endl;
    cin >> release; */
    //testing the size of a vector when defining it in creation

    /* system("COLOR 01");
    cout << "Printing in a different colour\n";
    system("COLOR 02");
    cout << "Trying a new colour\n"; */
    //changing the colour of the entire console output can't be used to highlight text

    cin >> release;
    return 1;
}

/* colour codes for "SetConsoleTextAttribute"
1- Blue
2- Green
3- Aqua
4- Red
5- Purple
6- Yellow
7- White
8- Gray
9- Light Blue
0- Black
10- Light Green
11- Light Aqua
12- Light Red
13- Light Purple
14- Light Yellow
15- Bright White */