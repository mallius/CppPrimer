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
	//1.以insert代替下标运算
	map<string, int> word_count;
	word_count.insert(map<string, int>::value_type("Anna", 1));
	cout << word_count["Anna"] << endl;

	word_count.insert(make_pair("Anna2", 2));
	cout << word_count["Anna2"] << endl;


	typedef map<string, int>::value_type valType;
	word_count.insert(valType("Anna3", 12));
	cout << word_count["Anna3"] << endl;

	//2.检测insert的返回值
	map<string, int> wordCount;
	string word;	
	cout << "Enter a word: ";
	cin >> word;

	pair<map<string,int>::iterator, bool> ret = wordCount.insert(make_pair(word, 1));
	cout << ret.first->second << endl; //1
	if(true==ret.second)
	{
		++ret.first->second;
	}
	cout << ret.first->second << endl; //2

	return 0;
}
