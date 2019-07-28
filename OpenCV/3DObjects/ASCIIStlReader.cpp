#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void establistMatrix(vector<vector<vector<int>>>& vec, int x, int y, int z)
{
    for ( int i = 0; i < z; i++)
    {
        vector <vector<int>> twoD;
        for ( int j = 0; j< y; j++)
        {
            vector <int> oneD;
            for (int k = 0; k < x; k++)
            {
                oneD.push_back(0);
            }
            twoD.push_back(oneD);
        }
        vec.push_back(twoD);
    }
}

int main(int argc, char* argv[])
{
    vector<vector<vector<int>>> matrix;
    establistMatrix(matrix, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

    unsigned int sum = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
        {
            for (int k=0;k<matrix.at(i).at(j).size();k++)
            {
                sum++;
            }
        }
    }
    cout << "sum: " << sum << endl;
    return 0;
}
