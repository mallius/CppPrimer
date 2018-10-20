#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz)
{
	return s.size() >= sz;
}

int main(void)
{
	auto check6 = bind(check_size, _1, 6);
	string s = "hello";
	bool b1 = check6(s);
	cout << b1 << endl;

	return 0;
}
