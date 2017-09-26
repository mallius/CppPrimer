#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	list<int> ilst;
	ilst.push_back(1);
	ilst.push_back(0);
	ilst.push_back(2);
	ilst.push_back(0);
	ilst.push_back(3);
	ilst.push_back(0);

	list<int>::reverse_iterator rit = find(ilst.rbegin(), ilst.rend(), 0);
	cout << *rit << endl;
	++rit;
	cout << *rit << endl;

	return 0;
}
