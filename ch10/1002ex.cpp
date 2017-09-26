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

	// 2
	vector<string> svec2;
	vector<int> ivec2;
	string inputStr;
	int inputInt;
	for(int i = 0; i < 2; i++)
	{
		cout << i+1 << "/2 " << "Enter string and int: ";
		cin >> inputStr >> inputInt;
		temp = pair<string, int>(inputStr, inputInt);

		svec2.push_back(temp.first);
		ivec2.push_back(temp.second);
	}

	// 输出2
	for(vector<string>::iterator it = svec2.begin(); it != svec2.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;

	for(vector<int>::iterator it = ivec2.begin(); it != ivec2.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;

	// 3
	vector<string> svec3;
	vector<int> ivec3;	
	for(int i = 0; i < 2; i++)
	{
		cout << i+1 << "/2 " << "Enter string and int: ";
		cin >> inputStr >> inputInt;
		temp = make_pair(inputStr, inputInt);

		svec3.push_back(temp.first);
		ivec3.push_back(temp.second);
	}
	
	// 输出3
	for(vector<string>::iterator it = svec3.begin(); it != svec3.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;

	for(vector<int>::iterator it = ivec3.begin(); it != ivec3.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;

	return 0;
}
