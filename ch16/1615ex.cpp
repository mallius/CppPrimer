#include <iostream>
#include <vector>
using namespace std;

template<class T>
int lenArray(T& array)
{
	return sizeof(array)/sizeof(array[0]);
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6};
	double darray[] = {1, 2.2, 3.3 };
	cout << lenArray(array) << endl;
	cout << lenArray(darray) << endl;
	return 0;
}
