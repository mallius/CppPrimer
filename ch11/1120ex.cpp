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

	for(vector<int>::iterator it = --ivec.end(); it != --ivec.begin(); --it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
