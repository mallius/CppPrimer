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
decltype(std::DeclValLeft<T_F>()   (std::DeclValLeft<U_Args>()...))：是int类型，也就是myfunc函数的返回类型
a)decltype(std::DeclValLeft<T_F>() )：是 int (* && )(int,int),函数指针的右值引用类型，其实就简单理解成函数指针类型
b)decltype(std::DeclValLeft<U_Args>()...)这种写法：推导出来的是两个int &&
***/

#include <iostream>
#include <boost/type_index.hpp>
using namespace std;

namespace _nmsp1
{	
	class A
	{
	public:
		A(int i)        //构造函数
		{
			printf("A::A(),this=%p\n", this);
		}
	
		double myfunc() //普通成员函数
		{
			printf("A::myfunc(),this=%p\n", this);
			return 12.1;
		}

	private:
		~A() {}
	};

	template <typename T>
	T&& DeclValRight() noexcept;

	template <typename T>
	T& DeclValLeft() noexcept;


	class ALR
	{
	public:
		void onAnyValue()
		{
			cout << "ALR::onAnyValue()" << endl;
		}

		void onLvalue()&  //只能被类ALR的左值对象调用
		{
			cout << "ALR::onLvalue()" << endl;
		}

		void onRvalue()&& //只能被类ALR的右值对象调用
		{
			cout << "ALR::onRvalue()" << endl;
		}
	};

}


int main()
{ 
	
	
	using boost::typeindex::type_id_with_cvr;
	
	cout << "decltype(DeclValRight<A>)())的返回类型  =" << type_id_with_cvr<decltype(_nmsp1::DeclValRight<_nmsp1::A>())>().pretty_name()   << endl;
	cout << "decltype(DeclValRight<A&>)())的返回类型 =" << type_id_with_cvr<decltype(_nmsp1::DeclValRight<_nmsp1::A&>())>().pretty_name()  << endl;
	cout << "decltype(DeclValRight<A&&>)())的返回类型=" << type_id_with_cvr<decltype(_nmsp1::DeclValRight<_nmsp1::A&&>())>().pretty_name() << endl;
	
	_nmsp1::ALR alr;             //左值对象alr
	alr.onLvalue();
	//alr.onRvalue();            //编译错误，因为onRvalue只能被类A的右值对象调用
	_nmsp1::ALR().onRvalue();    //临时对象是右值对象
	//_nmsp1::ALR().onLvalue();  //编译错误，因为onLvalue只能被类A的左值对象调用
	
#if 0
	//MSVC OK, GCC error
	decltype(_nmsp1::DeclValRight<_nmsp1::ALR>().onAnyValue());
	decltype(_nmsp1::DeclValRight<_nmsp1::ALR&>().onLvalue());    //返回的类型是class ALR &， 代表返回的是左值对象，左值对象调用onLvalue没问题
	decltype(_nmsp1::DeclValRight<_nmsp1::ALR&&>().onRvalue());   //返回的类型是class ALR &&，代表返回的是右值对象，右值对象调用onRvalue没问题
	//decltype(_nmsp1::DeclValRight<_nmsp1::ALR&>().onRvalue());  //返回的类型是class ALR &， 代表返回的是左值对象，左值对象调用onRvalue是错误的
	//decltype(_nmsp1::DeclValRight<_nmsp1::ALR&&>().onLvalue()); //返回的类型是class ALR &&，代表返回的是右值对象，右值对象调用onLvalue是错误的
	

	decltype(_nmsp1::DeclValLeft<_nmsp1::ALR>().onAnyValue()); 
	decltype(_nmsp1::DeclValLeft<_nmsp1::ALR&>().onLvalue());    //返回的类型是class ALR &，代表返回的是左值对象，左值对象调用onLvalue没问题
	//decltype(_nmsp1::DeclValLeft<_nmsp1::ALR&&>().onRvalue()); //返回的类型是class ALR &，代表返回的是左值对象，左值对象调用onRvalue是错误的
	//decltype(_nmsp1::DeclValLeft<_nmsp1::ALR&>().onRvalue());  //返回的类型是class ALR &，代表返回的是左值对象，左值对象调用onRvalue是错误的
	decltype(_nmsp1::DeclValLeft<_nmsp1::ALR&&>().onLvalue());   //返回的类型是class ALR &，代表返回的是左值对象，左值对象调用onLvalue没问#题
#endif	
	return 0;
}

