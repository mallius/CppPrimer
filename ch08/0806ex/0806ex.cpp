#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

istream& print(istream& in)
{
	int ival;
	while(in >> ival, !cin.eof())
	{
		if(in.bad())
			throw runtime_error("IO stream corrupted");
		if(in.fail())
		{
			cerr << "bad data, try again" << endl;
			in.clear();
			// in.setstate(istream::eofbit);
			in.ignore(2, ' ');
			continue;
		}
		cout << ival << endl;
	}
	in.clear();
	return in;
}

int main(void)
{
	ifstream infile;
	infile.open("0806test.txt");
	if(infile)
	{
		cout << "ok: input file 0806test.txt opened" << endl;
	}
	print(infile);
}
