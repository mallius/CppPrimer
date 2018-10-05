#include <iostream>
#include <vector>
using namespace std;

template <class T>
int count(vector<T>& v, T val)
{
	int ct = 0;
	for(typename vector<T>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if(*it == val)
			ct++;
	}
	return ct;
}

int main(void)
{
	int a[] = {1, 2, 3, 2, 5, 2};
	vector<int> ivec(a, a+6);
	int val = count(ivec, 2);
	cout << val << endl;
	return 0;
}
