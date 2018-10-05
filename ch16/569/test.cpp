#include "Queue.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	Queue<string> qs;
	qs.push("hello");
	qs.push("String");

	Queue<int> qi;
	short s = 42;
	int i = 42;
	qi.push(s);
	qi.push(i);

	cout << qi << endl;
	cout << qs << endl;

	// 使用函数模板成员函数
	short a[4] = {0, 3, 6, 9};
	Queue<int> qa(a, a+4);
	vector<int> vi(a, a+4);
	qa.assign(vi.begin(), vi.end());

	cout << qa << endl;

	return 0;
}
