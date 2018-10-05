#include "Queue.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	/**
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

	**/

	// 使用Queue<const char*>
	Queue<const char*> q1;      // 特例化版本只有编译器生成的默认构造函数
	q1.push("hi");              // 特例化版本将char*放入private的Queue<string>
	q1.push("bye"); 
	q1.push("world");
	Queue<const char*> q2(q1);  //特例化版本只有编译器生成的复制构造函数
	Queue<const char*> q3;
	q1 = q3;                    // 特例化版本只有编译器生成的赋值操作符

	return 0;
}
