#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> vec;
	for(vector<int>::size_type i = 0; i != 10; ++i)
	{
		vec.push_back(i);
	}
	vector<int>::reverse_iterator r_iter;
	for(r_iter = vec.rbegin(); r_iter != vec.rend(); ++r_iter)
	{
		cout << *r_iter << endl;
	}

	string line = "first,middle,last";
	string::iterator comma = find(line.begin(), line.end(), ',');
	cout << string(line.begin(), comma) << endl;
	string::reverse_iterator rcomma = find(line.rbegin(), line.rend(), ',');
	cout << string(line.rbegin(), rcomma) << endl;
	cout << string(rcomma.base(), line.end()) << endl;

	return 0;
}
