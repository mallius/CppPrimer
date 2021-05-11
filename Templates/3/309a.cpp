#include <iostream>
//#include <boost/type_index.hpp>
using namespace std;

namespace _nmsp1
{
	template<typename... Args>
	class myclasst
	{
	public:
		myclasst()
		{
			cout << "myclasst::myclasst(),sizeof...(Args)=" << sizeof...(Args) << endl;
		}
	};

	//1
	template<typename... Args>
	class myclasst1 :public myclasst<Args...>         //实例化后，myclasst<Args...> 代表的是一个类：myclasst<double,float,int>
	{
	public:
		myclasst1()
		{
			cout << "myclasst1::myclasst1(),sizeof...(Args)=" << sizeof...(Args) << endl;
		}
	};

	//2
	template<typename... Args>
	class myclasst2 :public myclasst<Args>...         
	{
	public:
		myclasst2()
		{
			cout << "myclasst2::myclasst2(),sizeof...(Args)=" << sizeof...(Args) << endl;
		}
	};

	//3
	template<typename... Args>
	class myclasst3 :public myclasst<Args, Args...>...         
	{
	public:
		myclasst3()
		{
			cout << "myclasst3::myclasst3(),sizeof...(Args)=" << sizeof...(Args) << endl;
		}
	};

	//4
	template<typename... Args>
	class myclasst4 :public myclasst<Args, char>...         
	{
	public:
		myclasst4()
		{
			cout << "myclasst4::myclasst4(),sizeof...(Args)=" << sizeof...(Args) << endl;
		}
	};
	
}

int main()
{ 
	_nmsp1::myclasst1<double, float, int> tmpobj1; 
	_nmsp1::myclasst2<double, float, int> tmpobj2; 
	_nmsp1::myclasst3<double, float, int> tmpobj3; 
	_nmsp1::myclasst4<double, float, int> tmpobj4; 
	
	return 0;
}

