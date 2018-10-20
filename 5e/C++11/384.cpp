#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	auto f = [] { return 42; };
	cout << f() << endl;

	[](const string& a, const string& b)
	{ return a.size() < b.size(); };


	return 0;
}
