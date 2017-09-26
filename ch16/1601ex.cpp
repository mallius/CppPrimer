#include <iostream>
using namespace std;

template<class T>
T Abs(const T& val)
{
	if(val < 0)
		return -val;
	return val;
}

int main(void)
{
	int i = -1;
	double d = -2.34;
	float f = -3.34;
	int val = 3;

	cout << Abs(i) << endl;
	cout << Abs(d) << endl;
	cout << Abs(f) << endl;
	cout << Abs(val) << endl;
}
