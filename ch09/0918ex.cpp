#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using std::string;
using std::vector;
using std::list;
using std::deque;
using std::cout;
using std::endl;
using std::cin;

int main(void)
{

	int array[] = {1,2,3,4,5,6,7,8};
	list<int> ilist(array, array+7);
	deque<int> d1, d2;
	for(list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
	{
		cout << *it << ", ";
		if(*it%2==0)
		{
			d1.push_back(*it);
		}
		else
		{
			d2.push_back(*it);
		}
	}
	cout << endl;

	for(deque<int>::iterator dit = d1.begin(); dit != d1.end(); ++dit)
	{
		cout << *dit << ", ";
	}
	cout << endl;

	for(deque<int>::iterator dit = d2.begin(); dit != d2.end(); ++dit)
	{
		cout << *dit << ", ";
	}
	cout << endl;

	return 0;
}
