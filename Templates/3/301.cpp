/***
第三章	 模板进阶知识
第一节 万能引用（universal reference / forwarding reference：转发引用）
（1）类型区别基本含义

（2）universal reference / 万能引用 / 未定义引用基本认识
结论：万能引用是一种类型。就跟int是一种类型是一个道理。再次强调，万能引用是一种类型。
右值引用（全称：右值引用类型）是用&&符号表示。右值引用是绑定到右值上。
万能引用离不开两种语境：
a)必须是函数模板
b)必须是发生了模板类型推断并且函数模板形参长这样：T&&
如果实参传递了一个整型左值给形参，tmprv的类型最终会被推断为int &类型。
如果果实参传递了一个整型右值给形参，tmprv的类型最终会被推断为int &&类型。
结论：T&&是一个万能引用类型。

题目:
void func(int&& param){...}   //右值引用，因为func不是函数模板而是一个普通函数。

template <typename T>
void func(T && tmpvalue){...} //是万能引用

template <typename T>
void func(std::vector<T>&& param) { ... } //右值引用

什么情形才是万能引用？
(a)一个是函数模板中用作函数参数的类型推断（参数中要涉及到类型推断），T&&
(b）auto &&tmpvalue = ..... 也是万能引用，这个后续再谈。
其他情况的&&，都是右值引用。

（3）万能引用资格的剥夺与辨认
（3.1）剥夺:const会剥夺 一个引用成为万能引用的资格，被打回原型成右值引用
（3.2）辨认
***/

#include <iostream>
#include <vector>

//#include <boost/type_index.hpp>
using namespace std;
//#pragma warning(disable : 4996) 


namespace _nmsp1
{	
	void  func(const int& abc) {}
	
	template <typename T>
	void  func(const T& abc) {} //T = int ,abc = const int&

	void myfunc(int&& tmprv)    //参数tmprv是个右值引用类型
	{
		cout << tmprv << endl;
		return;
	}

	/*
	template <typename T>
	void myfunc(T&& tmprv) //注意，&&是属于tmprv类型的一部分，不是T类型的一部分（&&和T类型没有关系）
	{
		tmprv = 12;        //不管tmprv的类型是左值引用还是右值引用，都可以给tmprv赋值。因为tmprv本身是个左值。
		cout << tmprv << endl;
		return;
	}
	*/
	
	
	template <typename T>
	void func(std::vector<T>&& param) 
	{ 

	} 
}

namespace _nmsp2
{
	
	template <typename T>
	void myfunc(T&& tmprv) //注意，&&是属于tmprv类型的一部分，不是T类型的一部分（&&和T类型没有关系）
	{
		tmprv = 12;        //不管tmprv的类型是左值引用还是右值引用，都可以给tmprv赋值。因为tmprv本身是个左值。
		cout << tmprv << endl;
		return;
	}
	
}

namespace _nmsp3
{
	template <typename T>
	void myfunc(const T&& tmprv)  //有const修饰，万能引用资格被剥夺，因为&&，所以只能是个右值引用
	{		
		cout << tmprv << endl;
		return;
	}

	template <typename T>
	class mytestc
	{
	public:
		void testfunc(T&& x) {};   //这个不是万能引用，而是右值引用,因为 testfunc成员函数本身没有涉及到类型推断。

	public:
		template <typename T2>
		void testfunc2(T2&& x) {}; //x类型是万能引用类型

	};
}



int main()
{ 
	/*测试_nmsp1*/
	_nmsp1::func(10);
	int&& rv = 1000;

	_nmsp1::myfunc(10); //正确，右值做实参。
	int i1 = 100;        //i左值
	//_nmsp1::myfunc(i1);  //错，右值 引用不能接（绑）左值。

	std::vector<int> aa = { 1 };
	_nmsp1::func(std::move(aa));

	int i2 = 100;
	//_nmsp1::myfunc(i2);           //不可以，只能传递右值进去，必须是std::move(i);
	_nmsp2::myfunc(std::move(i2));  

	/*测试_nmsp2*/
	int k1 = 100;
	_nmsp2::myfunc(k1);             //左值被传递，因此tmprv是个左值引用，也就是int&，最终i值变成12；
	printf("i2 = %d\n", k1);
	
	int k2 = 200;
	_nmsp2::myfunc(std::move(k2));  //右值被传递，因此tmprv是个右值引用，也就是int&&，最终i值变成12；
	printf("k2 = %d\n", k2);

    //测试_nmsp3
	_nmsp3::mytestc<int> mc;
	int j1 = 100;
	mc.testfunc(std::move(j1));  //左值不能绑定到右值引用上，必须修改为std::move(i);

	_nmsp3::mytestc<int> myoc;
	int j2 = 10;
	myoc.testfunc2(j2); //int &
	myoc.testfunc2(3);  //int &&

	return 0;
}
