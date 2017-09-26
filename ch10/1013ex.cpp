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
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	//insert参数类型为piar<const string, vector<int> >
	//返回值类型为pair<map<string, vector<int> >::iterator, bool >
	map<string, vector<int> > mapStringVec;
	pair< map<string, vector<int> >::iterator, bool> ret = 
										mapStringVec.insert(make_pair("a", vec));
	if(ret.second==true)
	{
		cout << "insert ok." << endl;
	}
	for(vector<int>::iterator it = ret.first->second.begin(); it != ret.first->second.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}
