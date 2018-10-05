/*
calc(0, ival) 候选有template <class T> T calc(T, T)和double calc(double, double)，选实例化
calc(0.25, dval) 候选同样上述两个，选普通函数
calc(0, fd) 一个为int,一个为float, 选普通函数唯一匹配
calc(0, 'J') 同上唯一匹配，选普通函数
*/

#include <iostream>
using namespace std;

template <class T> T calc(T, T)
{
	cout << "template <class T> T calc(T, T)" << endl;
}

double calc(double a, double b)
{
	cout << "double calc(double, double)" << endl;
}

template <> char calc<char>(char a, char b)
{
	cout << "template <> char calc<char>(char, char)" << endl;
}

int main(void)
{
	int ival;
	double dval;
	float fd;
	calc(0, ival);
	calc(0.25, dval);
	calc(0, fd);
	calc(0, 'J');
}
