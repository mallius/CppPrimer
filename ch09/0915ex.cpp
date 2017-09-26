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
	cout << "Enter a string: ";
	list<string> lvec;
	string temp;
	getline(cin, temp);
	lvec.push_back(temp);

	cout << "Enter a string: ";
	getline(cin, temp);
	lvec.push_back(temp);

	cout << "Enter a string: ";
	getline(cin, temp);
	lvec.push_back(temp);

	for(list<string>::iterator iter = lvec.begin(); iter != lvec.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}
