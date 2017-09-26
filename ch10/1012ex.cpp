#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;
int main(void)
{
	map<string, int> stringInt;
	string temp;
	for(int i = 0; i < 2; i++)
	{
		cout << i+1 << "times, please Enter a word: ";
		cin >> temp;
		pair<map<string, int>::iterator, bool> ret =  stringInt.insert(make_pair(temp, 1));
		if(ret.second==true)
		{
			cout << "You Enter :" << ret.first->first << " ";
			cout << ret.first->second << endl;
		}
	}
	return 0;
}
