#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;
int main(void)
{
	int array[] = {1,2,3};
	list<int> ilist(array, array+2);
	if(!ilist.empty())
	{
		list<int>::reference val = *ilist.begin();
		list<int>::reference val2 = ilist.front();

		cout << val2 << ", " << val << endl;

		list<int>::reference last = *--ilist.end();
		list<int>::reference last2 = ilist.back();

		cout << last << ", " << last2 << endl;
	}
	return 0;
}
