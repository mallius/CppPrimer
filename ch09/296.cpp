#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	string name("AnnaBelle");
	string::size_type pos1 = name.find("Anna");
	cout << pos1 << endl;

	string numerics("0123456789");
	string na("r2d2");
	string::size_type pos = na.find_first_of(numerics);
	cout << "found number at index: " << pos << " element is " << na[pos] << endl;
	return 0;
}
