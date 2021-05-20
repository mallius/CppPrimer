/***
第四章	标准库的典型内容
介绍C++标准库中典型且常用的函数模板、类模板、别名模板等功能组件以及他们的实现细节。
不要求学完后能运用自如，只要求，在课程辅助下，遇到实际代码时能够顺利阅读就达到了学习效果。

第一节 std::declval

（2.2）返回左值引用还是返回右值引用
decltype(mydeclval<A>)())的返回类型 = class _nmsp1::A &
decltype(mydeclval<A&>)())的返回类型 = class _nmsp1::A &
decltype(mydeclval<A&&>)())的返回类型 = class _nmsp1::A &

decltype(mydeclval<A>)())的返回类型 = class _nmsp1::A &&
decltype(mydeclval<A&>)())的返回类型 = class _nmsp1::A &
decltype(mydeclval<A&&>)())的返回类型 = class _nmsp1::A &&

（2.3）调用引用限定符修饰的成员函数范例

（3）推导函数返回值范例
T_F：是int (*)(int,int)类型，也就是函数指针类型
decltype(std::declval<T_F>()   (std::declval<U_Args>()...))：是int类型，也就是myfunc函数的返回类型
a)decltype(std::declval<T_F>() )：是 int (* && )(int,int),函数指针的右值引用类型，其实就简单理解成函数指针类型
b)decltype(std::declval<U_Args>()...)这种写法：推导出来的是两个int &&

***/

#include <iostream>
#include <boost/type_index.hpp>

using namespace std;
//#pragma warning(disable : 4996) 


//函数模板
//template <typename T>
//void myfunc(T  tmprv)
//{
//	cout << "--------------------------------begin----------------" << endl;
//	using boost::typeindex::type_id_with_cvr;
//	cout << "T=" << type_id_with_cvr<T>().pretty_name() << endl; //显示T的类型
//	cout << "tmprv=" << type_id_with_cvr<decltype(tmprv)>().pretty_name() << endl; //显示tmprv的类型
//	cout << "--------------------------------end------------------" << endl;
//}


namespace _nmsp1
{	
	class A
	{
	public:
		A(int i) //构造函数
		{
			printf("A::A()函数执行了,this=%p\n", this);
		}
	
		double myfunc() //普通成员函数
		{
			printf("A::myfunc()函数执行了,this=%p\n", this);
			return 12.1;
		}

	private:
		~A() {}
	};

	template <typename T>
	//T mydeclval() noexcept; //这里返回T &
	T& mydeclval() noexcept;
	//T&& mydeclval() noexcept;


	class ALR
	{
	public:
		void onAnyValue()
		{
			cout << "ALR::onAnyValue()函数执行了！" << endl;
		}

		void onLvalue()& //只能被类ALR的左值对象调用
		{
			cout << "ALR::onLvalue()函数执行了！" << endl;
		}

		void onRvalue()&& //只能被类ALR的右值对象调用
		{
			cout << "ALR::onRvalue()函数执行了！" << endl;
		}
	};

}

namespace _nmsp2
{
	int myfunc(int a, int b) //函数类型一般是由函数的返回值和参数类型决定，与函数名没有关系，所以myfunc代表的函数类型是: int(int,int);
	{
		return a + b;
	}

	//std::declval<>中的U_Args写成U_Args&&或者U_Args&
	//decltype(std::declval<T_F>() (std::declval<U_Args>()...))写法的作用：根据函数类型以及函数参数类型，推导函数返回值类型。
	template<typename T_F, typename... U_Args>
	decltype(std::declval<T_F>() (std::declval<U_Args>()...)) TestFnRtnImpl(T_F func, U_Args... args)
	//decltype(T_F(U_Args...)) TestFnRtnImpl(T_F func, U_Args... args) -报错：decltype不是这么用的，decltype后面圆括号中出现的一般都是变量、对象、表达式、函数名、函数指针名等等。
	{
		auto rtnvalue = func(args...);
		return rtnvalue;
	}
	
	//decltype(func(args...))：int类型，也就是myfunc的返回类型。
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
	
	using boost::typeindex::type_id_with_cvr;
	
	/*
	cout << "decltype(mydeclval<A>)())的返回类型=" << type_id_with_cvr<decltype(_nmsp1::mydeclval<_nmsp1::A>())>().pretty_name() << endl;
	cout << "decltype(mydeclval<A&>)())的返回类型=" << type_id_with_cvr<decltype(_nmsp1::mydeclval<_nmsp1::A&>())>().pretty_name() << endl;
	cout << "decltype(mydeclval<A&&>)())的返回类型=" << type_id_with_cvr<decltype(_nmsp1::mydeclval<_nmsp1::A&&>())>().pretty_name() << endl;
	*/

	/*
	_nmsp1::ALR alr;  //左值对象alr
	alr.onLvalue();
	//alr.onRvalue(); //编译错误，因为onRvalue只能被类A的右值对象调用
	_nmsp1::ALR().onRvalue();  //临时对象是右值对象
	//_nmsp1::ALR().onLvalue();  //编译错误，因为onLvalue只能被类A的左值对象调用
	*/

	/*
	decltype(_nmsp1::mydeclval<_nmsp1::ALR>().onAnyValue()); 
	decltype(_nmsp1::mydeclval<_nmsp1::ALR&>().onLvalue()); //返回的 类型是class ALR &，代表返回的是左值对象，左值对象调用onLvalue没问题
	decltype(_nmsp1::mydeclval<_nmsp1::ALR&&>().onRvalue()); //返回的 类型是class ALR &&，代表返回的是右值对象，右值对象调用onRvalue没问题
	//decltype(_nmsp1::mydeclval<_nmsp1::ALR&>().onRvalue());//返回的 类型是class ALR &，代表返回的是左值对象，左值对象调用onRvalue是错误的
	//decltype(_nmsp1::mydeclval<_nmsp1::ALR&&>().onLvalue()); //返回的 类型是class ALR &&，代表返回的是右值对象，右值对象调用onLvalue是错误的
	*/

	/*
	decltype(_nmsp1::mydeclval<_nmsp1::ALR>().onAnyValue());
	decltype(_nmsp1::mydeclval<_nmsp1::ALR&>().onLvalue()); //返回的 类型是class ALR &，代表返回的是左值对象，左值对象调用onLvalue没问题
	//decltype(_nmsp1::mydeclval<_nmsp1::ALR&&>().onRvalue()); //返回的 类型是class ALR &，代表返回的是左值对象，左值对象调用onRvalue是错误的
	//decltype(_nmsp1::mydeclval<_nmsp1::ALR&>().onRvalue());//返回的 类型是class ALR &，代表返回的是左值对象，左值对象调用onRvalue是错误的
	decltype(_nmsp1::mydeclval<_nmsp1::ALR&&>().onLvalue()); //返回的 类型是class ALR &，代表返回的是左值对象，左值对象调用onLvalue没问题
	*/

	/*_nmsp2测试*/
	auto res = _nmsp2::TestFnRtnImpl(_nmsp2::myfunc, 5, 5);                   //T_F被推断出 int(*)(int,int)
	cout << res << endl;

	auto result = _nmsp2::TestFnRtnImpl<int(int,int)>(_nmsp2::myfunc, 5, 7); //T_F被推断出 int(*)(int,int)
	cout << result << endl;
	
	//函数指针类型fp_var = int(*)(int,int)
	//函数指针的右值引用yy_fp_var = int(* &&)(int,int),现在yy_fp_var就可以代表fp_var
	int (*fp_var)(int x, int y);                            
	int (* &&yy_fp_var)(int x, int y) = std::move(fp_var);  
	fp_var = _nmsp2::myfunc;
	cout << fp_var(1, 2) << endl;    //输出值为3
	cout << yy_fp_var(1, 2) << endl; //输出值为3
	
	auto result2 = _nmsp2::TestFnRtnImpl2(_nmsp2::myfunc, 13, 15);
	cout << result2 << endl;
	
	return 0;
}

