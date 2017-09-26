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


bool findInt(vector<int>::iterator first, vector<int>::iterator last, int num)
{
	if(first > last)
	{
		cout << "first iterator > last iterator" << endl;
		return false;
	}

	for(; first != last; first++)
	{
		if(*first == num)
			return true;
	}
	return false;
}
int main(void)
{
	int arrayInt[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> vec(arrayInt, arrayInt+9);
	vector<int>::iterator first = vec.begin();
	vector<int>::iterator last = vec.end();

	bool ret = findInt(first, last, 8);
	cout << "result: " << ret << endl;

	return 0;
}
