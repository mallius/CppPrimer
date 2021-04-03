/***
第六节 模板的一些特殊继承关系说
（1）奇异（奇特）的递归模板模式（CRTP）:Curiously Recurring  Template Pattern。是一种模板编程手法：把派生类作为基类的模板参数：
（1.1）在基类中使用派生类对象
（1.2）基于减少派生类中代码量的考虑:出发点是尽可能把一些代码挪到基类中，从而有效的减少派生类中的代码量；
（1.3）基类调用派生类的接口与多态的体现(静态多态编程技术)
***/

#include <iostream>
using namespace std;

//(1.1)在基类中使用派生类对象
namespace _nmsp1
{
	template <typename T>  //T代表的就是派生类
	class Base             //Base是类模板
	{
	public:
		void asDerived()
		{
			T& derived = static_cast<T&>(*this); //派生类对象也是基类对象,所以这种静态类型转换没问题
			derived.myfunc();                    //调用派生类的成员函数
		}

	private:
		Base() {};
		friend T;                                //T派生类变成了友元类
	};

	class Derived1 : public Base<Derived1>       //Derived1是个普通类
	{
	public:
		void myfunc()
		{
			cout << "Derived1::myfunc()" << endl;
		}
		//......
	};

	class Derived2 : public Base<Derived2>       //Derived2是个普通类
	{
	public:
		void myfunc()
		{
			cout << "Derived2::myfunc()" << endl;
		}

	};
	
	template <typename T>
	class Derived3 : public Base<Derived3<T>>    //Derived3是个类模板
	{
	public:
		void myfunc()
		{
			cout << "Derived3::myfunc()" << endl;
		}

	};
}


int main()
{
	_nmsp1::Derived1 myd1;
	myd1.asDerived();        //调用基类的成员函数

	_nmsp1::Derived2 myd2;
	myd2.asDerived();        //调用基类的成员函数
	
	_nmsp1::Derived3<int> myd3;
	myd3.myfunc();

	return 0;
}
