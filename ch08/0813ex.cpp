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

ofstream& open_fileOut(ofstream& out, const string &file)
{
	out.close();
	out.clear();
	out.open(file.c_str());
	return out;
}

int main(void)
{
	ofstream out;
	string file("1.txt");
	open_fileOut(out, file);
	return 0;
}
