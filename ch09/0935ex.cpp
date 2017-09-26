#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main(void)
{
	string str = "This is a Text";
	for(string::iterator sit = str.begin(); sit != str.end(); ++sit)
	{
		if(isupper(*sit))
		{
			str.erase(sit);
			--sit;
		}
	}
	cout << str << endl;
	return 0;
}
