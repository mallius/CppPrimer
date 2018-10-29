#include <iostream>
using namespace std;

int main(void)
{
	int i;
	const int ci = 0;
	const int &j = i;
	const int *p = &ci;
	
	return 0;
}
