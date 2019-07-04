#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> numers, denoms;
int main()
{
    for (float numerator = 10; numerator < 100; numerator++)
    {
        for (float denominator = 10; denominator < 100; denominator++)
        {
            if (!(denominator==numerator))
            {
                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                                
                        const string& strNum = to_string(numerator);
                        const string& strDen = to_string(denominator);
                       
                        if (strNum.at(i) ==strDen.at(j))
                        {
                            const float fltNum = stof(to_string(strNum.at(i)));
                            const float fltDenom = stof(to_string(strDen.at(j)));
                            if (fltNum/fltDenom == numerator/denominator)
                            {
                                numers.push_back(numerator);
                                denoms.push_back(denominator);
                                cout << numerator << "/" << denominator << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
