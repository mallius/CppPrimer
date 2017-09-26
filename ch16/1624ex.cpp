#include <iostream>
using namespace std;

template <typename T>
int compare(const T& v1, const T& v2)
{
	if(v1 < v2) 
		return -1;
	if(v2 < v1) 
		return 1;
	return 0;
}



int main(void)
{
	short si = 1;
	int i = 2;
	cout << compare(static_cast<int>(si), i) << endl;
	return 0;
}
