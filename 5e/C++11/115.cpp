#include <iostream>
using namespace std;
int main(void)
{
	int ia[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	for(auto p = begin(ia); p != end(ia); ++p)
		for(auto q = begin(*p); q != end(*p); ++q)
			cout << *q << endl;
	return 0;
}
