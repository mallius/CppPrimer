#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str = "ab2c3d7R4E6";
	string letters = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string numers = "0123456789";

	string::size_type spos = 0;
	string::size_type nupos = 0;

	while((spos = str.find_first_of(letters, spos)) != string::npos)
	{
		cout << str[spos] << endl;
		spos++;
	}

	while((nupos = str.find_first_not_of(letters, nupos)) != string::npos)
	{
		cout << str[nupos] << endl;
		++nupos;
	}

	return 0;
}
