#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string s1("abc");
	string s2("def");
	string *ps1 = &s1;
	string *ps2 = &s2;
	vector<string *> psvec;
	psvec.push_back(ps1);
	psvec.push_back(ps2);

	for(vector<string *>::iterator it = psvec.begin(); it != psvec.end(); ++it)
	{
		cout << *(*it) <<  " size: " << (*it)->size() << endl;
	}
	return 0;
}
