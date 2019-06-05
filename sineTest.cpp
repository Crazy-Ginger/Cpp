#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
  // put your main code here, to run repeatedly:
  for(float i = 0.05; i < 3.1415926535; i+= 0.05)
  {
    float temp = sin(i)*200;
    cout << temp << endl;
  }
	return 1;
}