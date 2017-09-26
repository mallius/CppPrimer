#include <iostream>
#include <vector>
using namespace std;

template<class T>
void print(T& val)
{
	for(typename T::iterator it = val.begin(); it != val.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6};
	vector<int> ivec(array, array+6);
	print(ivec);
	return 0;
}
