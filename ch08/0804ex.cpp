#include <iostream>
#include <stdexcept>
using namespace std;
istream& print(istream& is)
{
	int ival;
	while(is >> ival, !cin.eof())
	{
		if(is.bad())
			throw runtime_error("IO stream corrupted");
		if(is.fail())
		{
			cerr << "bad data, try again";
			is.clear();
			is.setstate(istream::eofbit);
			continue;
		}
		cout << ival << endl;
	}
	is.clear();
	return is;
}

int main(void)
{
	cout << "Enter some words" << endl;
	print(cin);
	return 0;
}
