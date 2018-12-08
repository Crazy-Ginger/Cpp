#include <iostream>  //to output to the command line
#include <fstream>   //to read the text file that contains the matrix
#include <string>    //to read the text file that contains the matrix
#include <sstream>   //to alter the strings read from the text file into integers
#include <vector>    //to store the matricies
#include <windows.h> //to change the colour of the currect route using system
using namespace std;

int Traversal(vector<vector<int>> matrix)
{
    vector<vector<int>> sum = matrix; //creates a copy of the matrix for the sums to be stored in

    vector<vector<bool>> summed(matrix.size(), vector<bool>(matrix[0].size(), false)); /*creates an identically size matrix that allows the 
    program to check if the values have already been summed (this will use -1 for completely unchecked, 0 for edge solutions 
    then 1 for complete solutions)*/

    int x = 0, y = 0;
    int smallest = matrix.at(0).at(0); //sets the inittial value of the smallest as this is the smallest value it can be at the start


    while (x != 79 && y != 79)
    {
        summed.at(y).at(x) = true;
        sum.at(y).at(x) = smallest;

        smallest = 2147483647;

    }
}

int main()
{
    char release;
    fstream myfile;
    cin >> release;
    vector<vector<int>> matrix;
    vector<int> v_Row;

    int temp_value;
    string str_line;
    string str_Numb;
    if (release == '1') //allows the user to choose between the 5-by-5 matrix or the larger 80-by-80
    {
        myfile.open("Euler_Files/Problem81(test).txt");
    }
    else if (release == '2')
    {
        myfile.open("Euler_Files/Problem81.txt");
    }

    if (myfile.is_open())
    {

        while (getline(myfile, str_line)) //gets all the lines in the text file and sets a string equal to them
        {
            //cout << str_line << endl;     //debugging

            for (char c : str_line) //parses the entire string of each line
            {
                if (c == ',' || c == '.') //checks the curruent character to see if it should continue reading or if the current string is a complete number
                {
                    istringstream convert(str_Numb); //converts the string to an integer
                    if (!(convert >> temp_value))
                        cout << "Error in converstion\n";
                    //cout << "Added: " << temp_value << endl;  //part of testing
                    v_Row.push_back(temp_value); //adds the integer to the back on a vector
                    str_Numb.clear();            //clears the temporary string that held the number
                }
                else
                {
                    str_Numb += c; //if the character is an integer then the program adds it to back of a temp string
                }
            }
            if (v_Row.size() != 80 && release == '2') //checks that the correnct number of columns exisst in the matrix
            {
                cout << "Problem: " << v_Row.size() << endl;
                cout << str_line << endl;
                cin >> release;
            }
            matrix.push_back(v_Row); //adds the row of integers to the matrix

            cout << "Converted " << v_Row.size() << " numbers and added them" << endl;
            v_Row.clear();
            str_line.clear();
            str_Numb.clear();
        }
    }
    myfile.close();

    cout << "\nPrinting matrix\n";

    int columnCheck = matrix[0].size(); //to check that all the rows have the same number of columns in the matrix

    for (int i = 0; i < matrix.size(); i++) //outputs the entire matrix in a formatted fashion
    {
        if (matrix[i].size() != columnCheck)
        {
            cout << "Problem\n";
            cin >> release;
        }
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Number of rows: " << matrix.size() << endl
         << "Number of columns: " << columnCheck << endl;

    cin >> release;
    return 0;
}