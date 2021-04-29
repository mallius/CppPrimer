/***
（1）一个简单范例:对于重载的函数或者函数模板的选择上，编译器内部有一个自己的规则，
并不是简单粗暴的对函数就优先选择，对函数模板就靠后选择。
***/

#include <iostream>
#include <vector>

using namespace std;
 
namespace _nmsp1
{	
	template <typename T>
	void myfunc(const T& t)
	{
		cout << "myfunc函数模板执行了" << endl;
	}

	void myfunc(int tmpvalue)
	{
		cout << "myfunc(int)" << endl;
	}
	
	void myfunc(unsigned int tmpvalue)
	{
		cout << "myfunc(unsigned int)" << endl;
	}
	
	void myfunc(unsigned short tmpvalue)
	{
		cout << "myfunc(unsigned short)" << endl;
	}
}

int main()
{ 
	_nmsp1::myfunc(15);    //15编译器一般会认为是一个int类型的有符号数(int)
	_nmsp1::myfunc(15U);   //15U = unsigned int
	
	return 0;
}

