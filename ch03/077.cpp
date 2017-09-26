#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string s("Hello World!!!");
	string::size_type punct_cnt = 0;
	for(string::size_type index = 0; index != s.size(); ++index)
		if(ispunct(s[index]))
			++punct_cnt;
	cout << punct_cnt
		<< " punctuation characters in " << s << endl;
	for(string::size_type index = 0; index != s.size(); ++index)
		s[index] = tolower(s[index]);
	cout << s << endl;
	return 0;
}
