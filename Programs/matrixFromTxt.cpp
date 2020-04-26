#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


vector<vector<int>> MatrixGet(string codepath)
{
    fstream myfile;

    vector <vector <int>> matrix; 
    vector <int> v_Row; 

    int temp_value;
    string str_line;
    string str_Numb;

    myfile.open(codepath);
    matrix.clear();
    if (myfile.is_open())
    {
        //ensures that the entirity of the file is read
        while (getline(myfile, str_line))
        {
            //cout << str_line << endl;
            //moves through the string of each line and selects each char
            for (char c : str_line)
            {
                //if the char is a , or . then the element is converted and added to the row
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
            //after each line is read the contents of the row is added to the overall matrix
            matrix.push_back(v_Row);
            //cout << "Converted a line and added it" << endl;

            //clears the variables to ensure that each line is new and untainted
            v_Row.clear();
            str_line.clear();
            str_Numb.clear();
        }
    }
    myfile.close();
    return matrix;
}

int main()
{
    char release;
    vector <vector<int>> matrix = MatrixGet("matrixTest.txt");
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
