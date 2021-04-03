#include <iostream>
//#include "myclass.h"
#include "ca.h"

extern template class A<float>;                //模板实例化声明，其他.cpp源文件都这样写，本行一般写在.cpp源文件的上面位置
extern template void myfunc(int& v1, int& v2); //函数模板实例化声明

//#include <boost/type_index.hpp>
using namespace std;
//#pragma warning(disable : 4996) 

namespace _nmsp1
{
}

int main()
{
	//第七节 模板代码的组织结构与模板的显式实例化和声明
	//（1）模板代码的组织结构
	//普通类：类定义和类实现要分别放在.h头文件和.cpp源文件中。
	//编译项目时编译器会针对每个.cpp源文件作为一个编译单元来编译
	//如果多个.cpp源文件都实例化出来了MYClass<int>类，那么链接时编译器会选择其中一个MYClass<int>，其他的丢弃掉，这叫贪婪实例化。
	//类模板(函数模板)的定义和实现通常都放在.h头文件中，而不能把定义和实现代码分开。

	//（2）模板的显式实例化，模板声明，代码组织结构
	//通过显式 实例化 来避免这种生成多个相同类模板实例的开销。
	//总结：（1）使用vs2017,vs2019，不推荐使用类模板显式实例化特色。对于其他平台，有条件的自己测试。
	//(2)老师讲这节课的目的是为了让大家以后看到这种代码的时候不迷惑，看得懂。


	/*MYClass mycls;
	mycls.func();*/

	/*MYClass<int> mycls;
	mycls.func();*/


	A<float> a(1, 2);
	A<float> a2(1.1, 2.2);
	a.myft(3); //3

	A<int> d(6, 7); //int版本的A(A<int>)会被实例化出来。

	return 0;
}

