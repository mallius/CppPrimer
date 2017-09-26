#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int main(void)
{
	int ival;
	while(cin >> ival, !cin.eof())
	{
		if(cin.bad())
			throw runtime_error("IO stream corrupted");
		if(cin.fail())
		{
			cerr << "bad data, try again";
			cin.clear(istream::failbit);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
	return 0;
}
