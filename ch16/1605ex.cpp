#include <iostream>
using namespace std;

template<class T>
T bigger(T& a, T& b)
{
	if(a > b)
		return a;
	return b;
}

int main(void)
{
	int a = 1;
	int b = 2;
	double d1 = 1.0;
	double d2 = 2.1;
	cout << bigger(a, b) << endl;;
	cout << bigger(d1, d2) << endl;
}
