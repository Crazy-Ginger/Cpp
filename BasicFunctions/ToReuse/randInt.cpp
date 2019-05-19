#include <iostream>
//#include <stdlib.h>	//old random
#include <time.h>
#include <random>	//new sexier random
using namespace std;

int main()
{
	char release;
	//srand(time(NULL)); //inititaises random seed (old way)


	//generates random number
    random_device rd;
    default_random_engine rng(rd());

	uniform_int_distribution <> range(1, 10000); //creates a range from 1 to 10000 (inclusive)

//used to test the random works
/* 	double sum = 0;
	int temp;
	int average; */
	for (int i = 0; i < 100000; i++)
	{	
/* 		temp = range(rng);
		sum += temp; */
		cout << range(rng) << endl;	//selects a random number in the range of 1 to 10000 (inclusive)
	}
/* 	average = sum / 100000;
	cout << "average: " << average*2 << endl; */
	cin >> release;
	return 0;
}