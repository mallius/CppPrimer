#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;
int main(void)
{
	typedef pair<string, string> Author;
	pair<string, string> author("James", "Joyce");
	pair<string, int> word_count;

	Author proust("Marcel", "Proust");
	Author joyce("James", "Joyce");

	//pair对象的操作
	string firstBook;
	if(author.first == "James" && author.second == "Joyce")
		firstBook = "Stephen Hero";

	cout << "firstBook: " << firstBook << endl;

	//3.生成新的pair对象
	pair<string, string> next_auth;
	string first, last;

	cin >> first >> last;
	next_auth = make_pair(first, last);
	cout << "first: " << next_auth.first 
		<< ", second: " << next_auth.second << endl;

	cin >> next_auth.first >> next_auth.second;
	cout << "first: " << next_auth.first 
		<< ", second: " << next_auth.second << endl;


	return 0;
}
