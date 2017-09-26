#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int main(void)
{
	vector<int> ivec;
	for(vector<int>::size_type i = 0; i != 10; ++i)
	{
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.begin(), ivec.end());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;

	// 1. set中添加元素
	set<string> set1;
	set1.insert("the");
	set1.insert("and");

	set<int> iset2;
	iset2.insert(ivec.begin(), ivec.end());

	// 2. 从set中取元素	
	iset.find(1);
	iset.count(1);

	set<int>::iterator set_it = iset.find(1);
	cout << "set_it: " << *set_it << endl;

	return 0;
}
