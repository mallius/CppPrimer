/***
（2）替换失败并不是一个错误（SFINAE）:必须理解好。
SFINAE:Substitution Failure Is Not An Error，翻译成中文是“替换失败并不是一个错误”
SFINAE看成是C++语言的一种特性或者说一种模板设计中要遵循的重要原则，非常重要，务必理解好。
SFINAE特性是针对“函数模板重载”而言。
针对于函数模板而言，当用一个具体类型替换函数模板的参数时，可能会产生意想不到的问题 ：
比如产生一些毫无意义甚至是看起来语法上有错误的代码，对于这些代码，编译器并不一定报错，有可能是忽略——
编译器认为这个函数模板不匹配针对本次的函数调用，就当这个函数模板不存在一样。
转而去选择其他更匹配的函数或者函数模板，这就是所谓的“替换失败并不是一个错误”说法的由来。
SFINAE特性：我（编译器）虽然看不出你（实例化了的模板）的对错（错误一般指无效的类型，无效的表达式等），但是我能决定是否选择你，
当我觉得不合适的时候，我虽然不说你错，但是我忽略你（而不会选择你）；
***/

#include <iostream>
#include <vector>

using namespace std;
 
namespace _nmsp2
{
	template <typename T>
	typename T::size_type mydouble(const T& t)  //typename int::size_type mydouble(const int& t) ;
	{
		return t[0] * 2;
	}
	
	int mydouble(int i)
	{
		return i * 2;
	}
}

int main()
{ 

	_nmsp2::mydouble(15);

	vector<int> myvec;
	myvec.push_back(15);
	cout << _nmsp2::mydouble(myvec) << endl;

	//vector<int>::size_type
	
	return 0;
}

