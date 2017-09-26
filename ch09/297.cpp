#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	string numerics("0123456789");
	string na("r2d2");
	string::size_type pos = na.find_first_not_of(numerics);
	cout << "found number at index: " << pos << " element is " << na[pos] << endl;

	string river("Mississippi");
	string::size_type first_pos = river.find("is");
	string::size_type last_pos = river.rfind("is");
	cout << first_pos << endl;
	cout << last_pos << endl;
	return 0;
}
