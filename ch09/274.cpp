#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using std::string;
using std::vector;
using std::list;
using std::deque;
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	list<int> ilist;
	for(size_t ix = 0; ix != 4; ++ix)
		ilist.push_back(ix);	

	for(list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "---push_front---" << endl;
	list<int> ilist2;
	for(size_t ix = 0; ix != 4; ++ix)
		ilist2.push_front(ix);	

	for(list<int>::iterator it = ilist2.begin(); it != ilist2.end(); ++it)
	{
		cout << *it << endl;
	}
	
	cout << "--insert---" << endl;
	string spouse("Beth");
	vector<string> svec;
	list<string> slist;
	slist.insert(slist.begin(), spouse);

	svec.insert(svec.begin(), spouse);
	svec.insert(svec.end(), 3, "Ann");
	
	string sarray[4] = {"quasi", "simba", "frollo", "scar"};
	svec.insert(svec.end(), sarray, sarray+4);
	slist.insert(slist.end(), sarray+2, sarray+4);

	for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it)
	{
		cout << *it << endl;
	}	
	cout << "---slist---" << endl;
	for(list<string>::iterator it = slist.begin(); it != slist.end(); ++it)
	{
		cout << *it << endl;
	}	


	return 0;
}
