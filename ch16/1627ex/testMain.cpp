#include <iostream>
#include "middle.hpp"

int main(void)
{
	int a[] = {1, 3, 5, 7, 9};
	vector<int> ivec(a, a+4);
	int m = 0;
	middle(ivec, m);
	cout << m << endl;
	return 0;
}
