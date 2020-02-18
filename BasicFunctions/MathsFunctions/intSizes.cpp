#include <iostream>
using namespace std;

int main()
	{
	char release;

	//integer types but using standard form
	float flt;
	double dble;

	cout << "Max size of float: " << sizeof(flt) << endl;
	cout << "Max size of double: " << sizeof(dble) << endl;
	

	//large interger types with a lot of precision
	unsigned long long long_long_int;
	unsigned long long_int;
	unsigned int average_int;
	size_t s_t;

	cout << "Max size of long long: " << sizeof(long_long_int) << endl;
	cout << "Max size of long: " << sizeof(long_int) << endl;
	cout << "Max size of integer: " << sizeof(average_int) << endl;
	cout << "Max size of size_t: " << sizeof(s_t) << endl;

	cin >> release;
	return 0;
	}