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
	const char *words[] = {"This", "Is", "A", "Word"};
	list<string> slist(words, words+(sizeof(words)/sizeof(words[0])));
	for(list<string>::iterator iter = slist.begin(); iter != slist.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "----" << std::endl;
	list<string>::iterator riter = slist.end();
	--riter;
	for(; riter != slist.begin(); --riter)
	{
		std::cout << *riter << std::endl;
	}
	std::cout << *riter << std::endl;
	
	return 0;
}
