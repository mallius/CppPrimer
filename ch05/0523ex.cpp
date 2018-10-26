#include <iostream>
using namespace std;

int main(void)
{
	int x[10];
	int *p = x;
	cout << sizeof(x)/sizeof(*x) << endl;  //个数
	cout << sizeof(p)/sizeof(*p) << endl;  //指针大小8/int大小4=2
	return 0;
}
