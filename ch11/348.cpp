#include <vector>
#include <list>
#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> ivec;
	list<int> ilst;

	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(100);
	ivec.push_back(4);
	ivec.push_back(5);

	ilst.push_back(1);
	ilst.push_back(42);
	ilst.push_back(10);
	ilst.push_back(9);

	list<int>::iterator it = find(ilst.begin(), ilst.end(), 42);
	replace_copy(ivec.begin(), ivec.end(), inserter(ilst, it), 100, 0);

	for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		cout << *it << " " ;
	}
	cout << endl;

	for(list<int>::iterator it = ilst.begin(); it != ilst.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
