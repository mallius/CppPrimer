#include <iostream>
#include <vector>
#include <string>
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

template <> 
int count<char>(vector<char>& v, char val)
{
	// cout << "char 特例化" << endl;
	int ct = 0;
	for(vector<char>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if(*it == val)
			ct++;
	}
	return ct;
}

template <> 
int count<string>(vector<string>& v, string val)
{
	// cout << "string 特例化" << endl;
	int ct = 0;
	for(vector<string>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if(*it == val)
			ct++;
	}
	return ct;
}

int main(void)
{
	// vector<int>
	int a[] = {1, 2, 3, 2, 5, 2};
	vector<int> ivec(a, a+6);
	int val = count(ivec, 2);
	cout << val << endl;

	// vector<double>
	double d[] = {1.2, 1.1, 1.3, 1.2, 1.5};
	vector<double> dvec(d, d+5);
	val = count(dvec, 1.2);
	cout << val << endl;

	//vector<char>
	char c[] = {'a', 'b', 'a', 'd', 'e'};
	vector<char> cvec(c, c+5);
	val = count(cvec, 'a');
	cout << val << endl;

	//vector<string>
	string s[] = {"abc", "abc", "def", "ok"};
	string sval("abc");
	vector<string> svec(s, s+4);
	val = count(svec, sval);
	cout << val << endl;

	return 0;
}



