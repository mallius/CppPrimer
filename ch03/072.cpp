#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string line;
	// read line at time until end-of-file
	while(getline(cin, line))
		cout << line << endl;
	return 0;
}
