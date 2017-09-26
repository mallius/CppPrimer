#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;
int main(void)
{
	int array[] = {1,2,3};
	list<int> ilist(array, array+3);
	for(list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
	{
		cout << *it << endl;
	}

	while(!ilist.empty())
		ilist.pop_front();

	for(list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "----" << endl;
	string words[] = {"Abs", "Beth", "Cos", "Dua", "Eodo", "Fi", "Guasimodo", "Hs"};
	list<string> slist(words, words+sizeof(words) / sizeof(words[0]) );
	string searchValue("Guasimodo");

	list<string>::iterator siter = find(slist.begin(), slist.end(), searchValue);
	if(siter != slist.end())
		slist.erase(siter);

	for(list<string>::iterator it = slist.begin(); it != slist.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "---erase(s1, s2)----" << endl;
	list<string>::iterator s1 = find(slist.begin(), slist.end(), "Beth");
	list<string>::iterator s2 = find(slist.begin(), slist.end(), "Dua");
	slist.erase(s1, s2);

	for(list<string>::iterator it = slist.begin(); it != slist.end(); it++)
	{
		cout << *it << endl;
	}



	cout << "----" << endl;
	slist.clear();

	for(list<string>::iterator it = slist.begin(); it != slist.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}
