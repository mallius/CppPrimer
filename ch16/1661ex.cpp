#include <iostream>
#include <vector>
using namespace std;

template <typename T> int compare(const T& a, const T& b)
{
	cout << "compare(const T&, const T&)" << endl;
}

template <class U, class V> int compare(U, U, V)
{
	cout << "compare(U, U, V)" << endl;
}

int compare(const char* a, const char* b)
{
	cout << "compare(const char*, const char*)" << endl;
}

int main(void)
{
	compare(1, 0);

	vector<int> ivec1(10), ivec2(20);
	compare(ivec1.begin(), ivec1.end(), ivec2.begin());

	int ia1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	compare(ia1, ia1+10, ivec1.begin());	

	const char const_arr1[] = "world", const_arr2[] = "hi";
	compare(const_arr1, const_arr2);

	char ch_arr1[] = "world", ch_arr2[] = "hi";
	compare(ch_arr1, ch_arr2);

	return 0;
}
