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


typedef vector<int>::iterator iterInt;
vector<int>::iterator findInt(vector<int>::iterator first, vector<int>::iterator last, int num)
{
	if(first > last)
	{
		cout << "first iterator > last iterator" << endl;
	}

	for(; first != last; first++)
	{
		if(*first == num)
			return first;
	}
}
int main(void)
{
	int arrayInt[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> vec(arrayInt, arrayInt+9);
	vector<int>::iterator first = vec.begin();
	vector<int>::iterator last = vec.end();

	iterInt it = findInt(first,last, 8);
	cout << "result: " << *it << endl;

	return 0;
}
