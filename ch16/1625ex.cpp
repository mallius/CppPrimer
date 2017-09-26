#include <iostream>
#include <string>
using namespace std;

template <typename T>
int compare(const T& v1, const T& v2)
{
	if(v1 < v2) 
		return -1;
	if(v2 < v1) 
		return 1;
	return 0;
}



int main(void)
{
	string s1 = "Hello";
	string s2 = "hello";
	cout << compare(static_cast<std::string>(s1), static_cast<std::string>(s2)) << endl;
	return 0;
}
