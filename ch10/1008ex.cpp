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
	int val = 3;
	map<string, int> m;
	m["Ann"] = 1;
	
	//用迭代器再改值
	map<string, int>::iterator map_it = m.begin();
	map_it->second = val;

	cout << map_it->first << endl;
	cout << map_it->second << endl;

	return 0;
}
