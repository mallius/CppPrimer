#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	string s("hello world");
	string s2 = s.substr(6,5);
	string s3 = s.substr(6);
	cout << s2 << endl;
	cout << s3 << endl;

	string s4("C++ Primer");
	s4.append(" 3rd Ed.");
	cout << s4 << endl;

	s4.replace(11, 3, "4th");
	cout << s4 << endl;

	return 0;
}
