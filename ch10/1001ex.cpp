#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;
int main(void)
{
	pair<string, int> temp;
	vector<string> svec1;
	vector<int> ivec1;

	// 1
	for(int i = 0; i < 2; i++)
	{
		cout << i+1 << "/2 " << "Enter string and int: ";
		cin >> temp.first >> temp.second;

		svec1.push_back(temp.first);
		ivec1.push_back(temp.second);
	}

	// 输出1
	for(vector<string>::iterator it = svec1.begin(); it != svec1.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;

	for(vector<int>::iterator it = ivec1.begin(); it != ivec1.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;


	return 0;
}
