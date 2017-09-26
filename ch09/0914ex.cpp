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
	vector<string> svec;
	string temp;
	getline(cin, temp);
	svec.push_back(temp);

	cout << "Enter a string: ";
	getline(cin, temp);
	svec.push_back(temp);

	cout << "Enter a string: ";
	getline(cin, temp);
	svec.push_back(temp);

	for(vector<string>::iterator iter = svec.begin(); iter != svec.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}
