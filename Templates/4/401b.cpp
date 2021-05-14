#include <iostream>
#include <boost/type_index.hpp>

using namespace std;

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

	//这里返回T& ，不是T
	template <typename T>
	T& DeclVal() noexcept;
}

int main()
{   
	//利用boost输出类型名比typeid(...).name()用法输出类型名更准确。
	using boost::typeindex::type_id_with_cvr;

	cout << "DeclVal<A>()的返回类型=" <<  type_id_with_cvr<decltype(_nmsp1::DeclVal<_nmsp1::A>() )>().pretty_name() << endl;
	cout << "DeclVal<A>().myfunc()的返回类型=" << type_id_with_cvr<decltype(_nmsp1::DeclVal<_nmsp1::A>().myfunc())>().pretty_name() << endl; //语义限制
	cout << "sizeof(DeclVal<_nmsp1::A>())=" << sizeof(_nmsp1::DeclVal<_nmsp1::A>()) << endl;

	return 0;
}

