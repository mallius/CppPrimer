#include <iostream>
#include <string>
using namespace std;

template <typename T> int compare(const T& a, const T& b)
{
	if(a < b)
	{
		cout << a << endl;
		return a;
	}
	else
	{
		cout << b << endl;
		return b;
	}
}

void func(int(*pf1)(const string& s1, const string& s2))
{
	pf1;
}

void func(int(*pf2)(const int& a, const int& b))
{
	pf2;
}

int main(void)
{
	int (*pf)(const int & a, const int & b) = compare;
	func(pf);
	return 0;
}
