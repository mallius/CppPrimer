#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
	list<int> ilst {1, 2, 2, 3, 3, 4, 5};
	vector<int> ivec;

	unique_copy(ilst.begin(), ilst.end(), back_inserter(ivec));
	for(auto &x : ivec){
		cout << x << endl;
	}
}
