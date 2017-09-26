#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;
int main(void)
{
	list<int> ilist(10,42);
	ilist.resize(15);
	ilist.resize(25, -1);
	ilist.resize(5);

	int i = 0;
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter, ++i)
	{
		cout << i+1 << ": ";
		cout << *iter << endl;
	}
	return 0;
}
