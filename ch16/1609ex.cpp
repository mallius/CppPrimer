#include <iostream>
#include <vector>
using namespace std;
template <typename T, typename V>
T findElem(T first, T last, const V& val)
{
	while(first != last) 
	{
		if(*first == val)
			return first;
		++first;
	}
	return last;
}

int main(void)
{
	char arr[] = {1,2,3,4,5};
	vector<int> ivec(arr, arr+4);

	string s[] = {"a", "b", "c", "d", "e"};
	vector<string> svec(s, s+3);

	vector<int>::iterator it = findElem(ivec.begin(), ivec.end(), 3);	
	cout << *it << endl;

	vector<string>::iterator iter = findElem(svec.begin(), svec.end(), "c");
	cout << *iter << endl;
}
