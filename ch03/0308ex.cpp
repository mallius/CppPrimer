#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	//string str;
	//cout << str[0] << endl;

	string s1, s2;
	string s3;

	cout << "Enter two string 1: ";
	//getline(cin, s1);
	cin >> s1;
	cout << "Enter two string 2: ";
	cin >> s2;
	s3 = s1+s2;
	cout << s3 << endl;

	s3 = s1 + " " + s2;
	cout << s3 << endl;

	return 0;
}
