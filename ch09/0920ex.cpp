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
	vector<int> vec(10, 1);
	list<int> lst(10, 1);
	list<int> temp;
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		temp.push_back(*it);
	}
	if(temp==lst)
		cout << "list<int> == vector<int>" << endl;

	return 0;
}
