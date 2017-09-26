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
	map<string, int> word_count;
	word_count["Anna"] = 1;
	map<string, int>::iterator map_it = word_count.begin();
	cout << map_it->first;
	cout << " " << map_it->second
		<< endl;

	++map_it->second;

	cout << map_it->second << endl;

	//1.下标操作符返回值的使用
	cout << word_count["Anna"] << endl;
	++word_count["Anna"];
	cout << word_count["Anna"] << endl;

	//2.下标行为的编程意义
	string word;
	cout << "Please enter a word: ";
	cin >> word;
	++word_count[word];

	cout << word_count[word]
		<< endl;

	return 0;
}
