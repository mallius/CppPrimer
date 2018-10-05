#include <string.h>
#include <iostream>
using namespace std;

template <typename T>
int compare(const T& v1, const T& v2)
{
	// cout << "实例化" << endl;
	if(v1 < v2) return -1;
	if(v2 < v1) return 1;
	return 0;
}

template <>
int compare<const char*>(const char* const& v1, const char* const& v2)  // 指针的引用？
{
	// cout << "特例化" << endl;
	return strcmp(v1, v2);	
}

int main(void)
{
	const char* cp1 = "world", *cp2 = "hi";
	int i1, i2;
	compare(cp1, cp2);
	compare(i1, i2);
	return 0;
}
