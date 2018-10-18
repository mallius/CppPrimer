#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v;
	const vector<int> cv;
	auto it = v.cbegin();	
	auto it2 = cv.cbegin();
	return 0;
}
