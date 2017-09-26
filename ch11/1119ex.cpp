#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);

	for(vector<int>::reverse_iterator rit = ivec.rbegin(); rit != ivec.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;

	return 0;
}
