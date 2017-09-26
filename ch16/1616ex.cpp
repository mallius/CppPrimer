#include <iostream>
#include <vector>
using namespace std;


template<class T>
void PrintValues(T& array)
{
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6};
	double darray[] = {1, 2.2, 3.3 };
	PrintValues(array);
	PrintValues(darray);

	return 0;
}
