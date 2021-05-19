/***
第四章	标准库的典型内容
第一节 std::declval

（2.2）返回左值引用还是返回右值引用
decltype(DeclValRight<A>)())的返回类型 = class _nmsp1::A &
decltype(DeclValRight<A&>)())的返回类型 = class _nmsp1::A &
decltype(DeclValRight<A&&>)())的返回类型 = class _nmsp1::A &

decltype(DeclValRight<A>)())的返回类型 = class _nmsp1::A &&
decltype(DeclValRight<A&>)())的返回类型 = class _nmsp1::A &
decltype(DeclValRight<A&&>)())的返回类型 = class _nmsp1::A &&

（2.3）调用引用限定符修饰的成员函数范例

（3）推导函数返回值范例
T_F：是int (*)(int,int)类型，也就是函数指针类型
decltype(std::DeclValLeft<T_F>()   (std::DeclValLeft<U_Args>()...))：是int类型，也就是Add函数的返回类型
a)decltype(std::DeclValLeft<T_F>() )：是 int (* && )(int,int),函数指针的右值引用类型，其实就简单理解成函数指针类型
b)decltype(std::DeclValLeft<U_Args>()...)这种写法：推导出来的是两个int &&
***/

#include <iostream>
//#include <boost/type_index.hpp>
using namespace std;

namespace _nmsp2
{
	//函数类型一般是由函数的返回值和参数类型决定，与函数名没有关系，所以Add代表的函数类型是: int(int,int);
	int Add(int a, int b) 
	{
		return a + b;
	}

	//std::declval<>中的U_Args写成U_Args&&或者U_Args&
	//decltype(std::declval<T_F>() (std::declval<U_Args>()...))写法的作用：根据函数类型以及函数参数类型，推导函数返回值类型。
	//decltype(T_F(U_Args...)) TestFnRtnImpl(T_F func, U_Args... args) -报错：
	//decltype后面圆括号中出现的一般都是变量、对象、表达式、函数名、函数指针名等等。
	template<typename T_F, typename... U_Args>
	decltype(std::declval<T_F>() (std::declval<U_Args>()...)) TestFnRtnImpl(T_F func, U_Args... args)
	{
		auto rtnvalue = func(args...);
		return rtnvalue;
	}
	
	//decltype(func(args...))：int类型，也就是Add的返回类型。
	//decltype(func)：int(*)(int,int)类型，函数指针类型
	template<typename T_F, typename... U_Args>
	auto TestFnRtnImpl2(T_F func, U_Args... args)->decltype(func(args...)) 		                                                                   
	{
		auto rtnvalue = func(args...);
		return rtnvalue;
	}
	
}

int main()
{ 
	/*_nmsp2测试*/
	//函数指针类型fp_var = int(*)(int,int)
	//函数指针的右值引用rr_fp_var = int(* &&)(int,int),现在rr_fp_var就可以代表fp_var
	int (*fp_var)(int x, int y);                            
	int (* &&rr_fp_var)(int x, int y) = std::move(fp_var);  
	fp_var = _nmsp2::Add;
	cout << fp_var(1, 2) << endl;    //输出值为3
	cout << rr_fp_var(1, 2) << endl; //输出值为3
	
	auto result1 = _nmsp2::TestFnRtnImpl(_nmsp2::Add, 5, 5);                   //T_F被推断出 int(*)(int,int)
	cout << result1 << endl;

	auto result2 = _nmsp2::TestFnRtnImpl<int(int,int)>(_nmsp2::Add, 5, 7);  //T_F被推断出 int(*)(int,int)
	cout << result2 << endl;
	
	auto result3 = _nmsp2::TestFnRtnImpl2(_nmsp2::Add, 15, 15);
	cout << result3 << endl;
	
	return 0;
}

