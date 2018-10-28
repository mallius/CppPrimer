#include <iostream>
#include <list>
using namespace std;
int main(void)
{
	list<string> lst{"a", "ab", "abc"};
	string word{"abcd"};

	auto iter = lst.begin();
	iter = lst.insert(iter, word);

	cout << *iter << endl;

	return 0;
}
