#include <iostream>
#include <stdexcept>
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
			cerr << "bad data, try again";
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
	cout << "Enter some words" << endl;
	print(cin);
	return 0;
}
