#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

int main(void)
{
	string str;
	vector<string> svec;
	svec.push_back("aBc");
	svec.push_back("def");
	svec.push_back("hiG");
	for(vector<string>::size_type ix = 0; ix != svec.size(); ++ix)
	{
		for(string::size_type is = 0; is < svec[ix].length(); ++is)
		{
			if(islower(svec[ix][is]))
				svec[ix][is] -= 32;
		}
		cout << svec[ix] << " ";
	}
	cout << endl;
	return 0;
}
