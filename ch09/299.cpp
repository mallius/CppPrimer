#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	string cobol("abend");
	string cplus("abort");
	cout << cobol.compare(cplus);
	return 0;
}
