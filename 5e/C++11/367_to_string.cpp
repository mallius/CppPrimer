#include <iostream>
using namespace std;

int main(void)
{
	int i = 42;
	string s = to_string(i);
	cout << s << endl;

	double d = stod(s);
	cout << d << endl;

	string s2 = "pi = 3.14";
	d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
	cout << d << endl;

	return 0;
}
