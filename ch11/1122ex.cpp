#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
	vector<int> ivec;
	list<int> ilst;

	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	ivec.push_back(5);
	ivec.push_back(6);
	ivec.push_back(7);
	ivec.push_back(8);
	ivec.push_back(9);
	ivec.push_back(10);


	copy(ivec.rbegin()+3, ivec.rend()-2, back_inserter(ilst));	
	for(list<int>::iterator it = ilst.begin(); it != ilst.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
