#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    char release;
    fstream myfile;

    vector <vector <int>> matrix; 
    vector <int> v_Row; 

    int temp_value;
    string str_line;
    string str_Numb;

    myfile.open("Euler_Files/Problem81(test).txt");
    matrix.clear();
    if (myfile.is_open())
    {
        
        while (getline(myfile, str_line))
        {
            cout << str_line << endl;
            
            for (char c : str_line)
            {
                if (c==',' || c=='.')
                {
                    istringstream convert(str_Numb);
                    if (!(convert >> temp_value))
                    cout << "Error in converstion\n";

                    v_Row.push_back(temp_value);
                    str_Numb.clear();
                }
                else
                {
                    str_Numb += c;
                }
            }
            matrix.push_back(v_Row);
            cout << "Converted a line and added it" << endl;
            v_Row.clear();
            str_line.clear();
            str_Numb.clear();
        }
    }
    myfile.close();

    cout << "\nPrinting matrix\n";

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
	
    
    cin >> release;
    return 0;

}