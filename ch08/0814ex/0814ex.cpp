#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <cstring>

using namespace std;

ifstream& open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

int main(void)
{
	ifstream infile;
	string file("1.txt");
	string str;
	if(!open_file(infile, file.c_str()))
	{
		cout << "open_file 1.txt error." << endl;
		return -1;
	}
	while(getline(infile, str))
	{
		cout << str << endl;
	}

	return 0;
}
