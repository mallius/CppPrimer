// g++ -std=c++11 0926.cpp
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

bool isOu(int n)
{
	if(n%2 == 0)
		return true;
	return false;
}

using namespace std;
int main(void)
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	vector<int> ivec(ia, ia+sizeof(ia)/sizeof(ia[0]));
	list<int> ilist(ia, ia+sizeof(ia)/sizeof(ia[0]));

	//处理前	
	cout << "---befor erase, vector and list---" << endl;
	for(auto &x : ivec)
	{
		cout << x << ", ";
	}
	cout << endl;
	for(auto &x : ilist)
	{
		cout << x << ", ";
	}
	cout << endl;

	//处理
	for(auto iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		if(*iter%2 != 0)
		{
			iter = ivec.erase(iter);
			--iter;
		}
	}
	for(auto iter = ilist.begin(); iter != ilist.end(); ++iter)
	{
		if(*iter%2 == 0)
		{
			iter = ilist.erase(iter);
			--iter;
		}
	}

	//处理后
	for(auto &x : ivec)
	{
		cout << x << ", ";
	}
	cout << endl;
	for(auto &x : ilist)
	{
		cout << x << ", ";
	}
	cout << endl;
	return 0;
}
