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
	//查找并读取map的元素
	
	map<string, int> wordCnt;
	int occ = wordCnt["Foo"]; //下标的危险的副作用,不存在则插入
	cout << wordCnt["Foo"] << endl;

	map<string, int> word_count;
	word_count.insert(make_pair("foobar", 2));
	//word_count["foobar"] = 3;

	if(word_count.count("foobar"))
	{
		int ret = word_count.count("foobar");
		cout << ret << endl;
	}

	int occurs;
	map<string, int>::iterator it = word_count.find("foobar");
	if(it != word_count.end())
		occurs = it->second;
	cout << occurs << endl;

	//从map中删除元素
	string removal_word = "foobar";
	if(word_count.erase(removal_word))
		cout << "ok: " << removal_word << " removed\n";
	else 
		cout << "oops: " << removal_word << " not found!\n";


	word_count.insert(make_pair("foobar", 100));

	//map对象的迭代遍历
	map<string, int>::const_iterator map_it = word_count.begin();
	while(map_it != word_count.end())
	{
		cout << map_it->first << " occurs " << map_it->second << " (map_it->second)times" << endl;
		++map_it;
	}

	return 0;
}
