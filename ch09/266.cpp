#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using std::string;
using std::vector;
using std::list;
using std::deque;

int main(void)
{
	vector<string> svec(10, "hello");
	list<string> slist(svec.begin(), svec.end());
	for(list<string>::const_iterator it = slist.begin(); it != slist.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	vector<string>::iterator mid = svec.begin() + svec.size()/2;
	deque<string> front(svec.begin(), mid);
	deque<string> back(mid, svec.end());

	//char *words[] = {"stately", "plup", "buck", "mulligan"};
	const char *words[] = {"stately", "plup", "buck", "mulligan"};
	size_t words_size = sizeof(words)/sizeof(char *);
	list<string> word2(words, words+ words_size);

	const list<int>::size_type list_size = 64;
	list<string> slist2(list_size, "eh?");
	list<int> ilist(list_size);

	return 0;
}
