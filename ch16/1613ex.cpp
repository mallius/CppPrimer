#include <iostream>
#include <vector>
using namespace std;

template<class T>
void print(T& val)
{
	typename T::size_type index = 0;
	while(index < val.size())
	{
		cout << val[index] << " ";
		index++;
	}
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6};
	vector<int> ivec(array, array+6);
	print(ivec);
	return 0;
}
