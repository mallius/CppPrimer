#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	cout << "Enter two strings: ";
	string s1, s2;
	cin >> s1 >> s2;
	if(s1 == s2)
		cout << "s1==s2" <<endl;
	else if(s1 < s2)
		cout << "s1 < s2" << endl;
	else
		cout << "s1 > s2" << endl;
	string::size_type len1 = s1.size();
	string::size_type len2 = s2.size();
	if(len1 == len2)
		cout << "s1 s2 length equal" << endl;
	else if(len1 < len2)
		cout << "s2 longer" << endl;
	else
		cout << "s1 longer" << endl;

	cout << "s1.size(): " << s1.size() << endl;
	cout << "s2.size(): " << s2.size() << endl;	
	return 0;
}
