#include <iostream>
using namespace std;

void fcn1()
{
	size_t v1 = 42;
	auto f = [v1] { return v1; };
	v1 = 0;
	auto j = f();
	cout << j << endl;
}

void fcn2()
{
	size_t v1 = 42;
	auto f2 = [&v1] { return v1; };
	v1 = 0;
	auto j = f2();
	cout << j << endl;
}

void fcn3()
{
	size_t v1 = 42;
	auto f = [v1] () mutable { return ++v1; };
	v1 = 0;
	auto j = f();
	cout << j << endl;
}

void fcn4()
{
	size_t v1 = 42;
	auto f2 = [&v1] { return ++v1; };
	v1 = 0;
	auto j = f2();
	cout << j << endl;
}

int main(void)
{
	fcn1();
	fcn2();
	fcn3();
	return 0;
}
