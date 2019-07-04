#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> numers, denoms;
int main()
{
    bool print = false;
    for (float numerator = 10; numerator < 100; numerator++)
    {
        for (float denominator = 10; denominator < 100; denominator++)
        {
            cout << "num: " << numerator << "\tden: " << denominator << endl;
            //if (numerator==49 && denominator==98)
            //{
                //print = true;
                //cout << numerator << "/" << denominator << ":\n";
            //}
            //else
            //{
                //print = false;
                //cout << "done\n";
            //}

            //if (!(denominator==numerator))
            //{
                //for (int i = 0; i < 2; i++)
                //{
                    //for (int j = 0; j < 2; j++)
                    //{
                        //string strNum = to_string(numerator);
                        //string strDen = to_string(denominator);
                       
                        //if (strNum.at(i) ==strDen.at(j))
                        //{
                            //const float fltNum = stof(to_string(strNum.at(i)));
                            //const float fltDenom = stof(to_string(strDen.at(j)));
                            //cout << fltNum << "/" << fltDenom << endl;
                            //if (fltNum/fltDenom == numerator/denominator)
                            //{
                                //numers.push_back(numerator);
                                //denoms.push_back(denominator);
                                //cout << numerator << "/" << denominator << "\tadding" << endl;
                            //}
                        //}
                    //}
                //}
            //}
        }
    }

    return 0;
}
