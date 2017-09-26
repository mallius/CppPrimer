#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{

	string str;
	vector<string> svec;
	ifstream infile("1.txt");
	if(!infile)
	{
		cout << "open 1.txt error." << endl;
		return -1;
	}
	
	while(getline(infile, str))
	{
		svec.push_back(str);
	}
	for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
