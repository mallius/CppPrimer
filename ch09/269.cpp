
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using std::string;
using std::vector;
using std::list;
using std::deque;


int main(void)
{
	vector<int> vec(10, 1);
	vector<int>::iterator iter = vec.begin() + vec.size()/2;
	list<int> ilist(vec.begin(), vec.end());

	// ilist.begin() + ilist.size()/2;  error list迭代器不支持算术运算和关系运算
	return 0;
}
