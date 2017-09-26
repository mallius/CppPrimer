#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;
int main(void)
{
	string words[] = {"A", "B", "C", "D", "E", "F"};
	list<string> slist(words, words+6);
	deque<string> sdque(words, words+6);

	string searchVal("F");	

	// erase
	list<string>::iterator iter = find(slist.begin(), slist.end(), searchVal);
	if(iter != slist.end())
		slist.erase(iter);

	for(list<string>::iterator it = slist.begin(); it != slist.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;

	//erase
	deque<string>::iterator diter = find(sdque.begin(), sdque.end(), searchVal);
	if(diter != sdque.end())
		sdque.erase(diter);

	for(deque<string>::iterator it = sdque.begin(); it != sdque.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;

	return 0;
}
