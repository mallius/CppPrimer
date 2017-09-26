#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	vector<int> vec;

	fill_n(back_inserter(vec), 5, 0);	

	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
