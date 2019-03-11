//#include <stdlib.h>   //used for random first but range wasn't large enough
#include <random>   //new random
#include <time.h>   //used for sleeping the console
#include <windows.h>    //used to change the colour highlighting of the console
//the usual stuff
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //allows the colour to be changed (don't know how)
    //srand(time(NULL));  //creates the random seed when using rand()
    
    char release;

    //generates random number
    random_device rd;
    default_random_engine rng(rd());


    //gets the strings from the file and puts them into a vector
    fstream myfile;
    vector <string> words;
    string word;
    myfile.open("C:\\Coding\\words.txt");

    if (!myfile.is_open())
    {
        cout << "Failed to open\n";
    }
    while (getline(myfile, word))
    {
        words.push_back(word);
    }
    //outputs the size of the vector cotaining all the words
    cout <<"Words size: " << words.size() << endl;
    cin >> release;

    //new random using uniform distribution
    uniform_int_distribution<> rand_colours(1,15);
    uniform_int_distribution<> rand_words(0, words.size());

    //outputs random words of random colours forever
    while (true)
    {
        //int temp_colour = rand() % 15 + 1;    //old random
        SetConsoleTextAttribute(color, rand_colours(rng));
        
        //long word_int = rand();    //old random 
        //cout << word_int << endl;
        cout << words.at(rand_words(rng));
        //Sleep(1);   //causes the console to pause for 1 millisecond before printing the next word
    }

    return 0;
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