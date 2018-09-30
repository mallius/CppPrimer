#include <iostream>
using namespace std;

template <class Type> Type sum(const Type &op1, int op2)
{
	return op1 + op2;
}

template<typename T> int compare(const T&, const T&)
{

	return 0;
}

int main(void)
{
	double d = 3.14;
	string s1("hiya"), s2(" world");
	sum(1024, d);
	sum(1.4, d);
	// sum(s1, s2); //error

	int (*pf1)(const int&, const int&) = compare;
}
