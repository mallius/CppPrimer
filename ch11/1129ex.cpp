// g++ -std=c++11 thisfile.cpp
#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	list<int> ilst {1,2,7,7,6,6,5};
	ilst.sort();
	ilst.unique();
	for(auto &x : ilst) {
		cout << x << endl;
	}
}
