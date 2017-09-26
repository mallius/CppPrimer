#include <iostream>
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

template <typename A, typename B>
int compare(const A& v1, const B& v2)
{
	if(v1 < v2) 
		return -2;
	if(v2 < v1) 
		return 2;
	return 0;
}


int main(void)
{
	short s1=1, s2=2;
	short si = 1;
	int i = 2;
	cout << compare(s1, s2) << endl;
	cout << compare(si, i) << endl;
	return 0;
}
