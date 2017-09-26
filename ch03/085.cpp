#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> vec(10);
	for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter <<endl;
	}

	for(vector<int>::const_iterator const_iter = vec.begin();
			const_iter != vec.end(); const_iter++)
	{
		cout << *const_iter << endl;
		//*const_iter = 1;
	}

	vector<int> nums(10);
	const vector<int>::iterator cit = nums.begin();
	//*cit = 1;
	++cit;
}
