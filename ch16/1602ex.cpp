#include <iostream>
using namespace std;

template<typename T>
void printVal(ostream & os, T val)
{
	os << val;
}

int main(void)
{
	int i = 1;
	printVal(cout, i);
	cout << endl;
	printVal(cout, "Hello");
	cout << endl;
	return 0;
}
