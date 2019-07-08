#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned int nT = 1; //285;
    unsigned int nP = 1; //165;
    unsigned int nH = 1; //143;
    
    bool answer = false;
    while (!answer)
    {
       unsigned int currentT =  nT*(nT+1)/2;
       unsigned int currentP = nP*(3*nP -1)/2;
       while (currentT <= currentP)
       {
           if (currentT == currentP)
           {
               cout << currentT << "\tnT: " << nT << "\tnP: " << nP << endl;
               unsigned int currentH = ;
               while (currentT < currentH)
               {

               }
           }
           else
           {
               nP++;
               currentP = nP*(3*nP -1)/2;
           }
        nT++;
       }
    }
}
