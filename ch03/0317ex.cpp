#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> ivec;
	for(int i = 0; i < 5; ++i)
	{
		ivec.push_back(i);
	}
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		*it = *it*2;
	}
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		cout << *it << " ";
	}
	return 0;
}
