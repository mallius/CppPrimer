#include <iostream>
using namespace std;
template <typename T> 
T fobj(T, T)
{

}

template <typename T>
T fref(const T&, const T&)
{

}

int main(void)
{
	string s1("a value");
	const string s2("another value");
	// fobj(s1, s2);
	// fref(s1, s2);
	
	int a[10], b[42];
	fobj(a, b);
	// fref(a, b);  const 无法匹配
}
