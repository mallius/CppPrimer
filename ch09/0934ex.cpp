#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main(void)
{
	string str = "This is a Text";
	for(string::iterator sit = str.begin(); sit != str.end(); ++sit)
	{
		*sit = toupper(*sit);
	}
	cout << str << endl;
	return 0;
}
