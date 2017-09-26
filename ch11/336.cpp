#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int search_item = 42;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(42);
	vector<int>::iterator result = find(vec.begin(), vec.end(), search_item);
	if(result == vec.end())
		cout << "Not Found";
	else 
		cout << "Found" << endl;
	
	list<int> ilist;
	ilist.push_back(1);
	ilist.push_back(1);
	ilist.push_back(42);

	list<int>::iterator it = find(ilist.begin(), ilist.end(), search_item);
	if(it == ilist.end())
		cout << "Not Found";
	else
		cout << "Found" << endl;;

	return 0;
}
