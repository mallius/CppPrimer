#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(42);

	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << endl;
	}

	fill_n(vec.begin(), 5, 0);	

	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
