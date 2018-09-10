#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

istream& print(istream& in)
{
	string sval, outval;

	while(in >> sval, !cin.eof())
	{
		if(in.bad())
			throw runtime_error("IO stream corrupted");
		if(in.fail())
		{
			cerr << "bad data, try again";
			in.clear();
			// in.setstate(istream::eofbit);
			in.ignore(2, ' ');
			continue;
		}

		istringstream istream(sval);
		while(istream >> outval) 
		{
			cout << outval << endl;
		}
	}
	in.clear();
	return in;
}

int main(void)
{
	cout << "Enter some int numbers" << endl;
	print(cin);
	return 0;
}
