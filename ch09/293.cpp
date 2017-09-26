#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	const char *cp = "Stately plump Buck";
	string s;
	s.assign(cp, 7);
	cout << s << endl;
	s.insert(s.size(), cp+7);
	cout << s << endl;
	return 0;
}
