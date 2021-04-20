#include <iostream>
using namespace std;

namespace _nmsp2
{
	void printInfo(int& t)
	{
		cout << "printInfo()参数类型为左值引用" << endl;
	}

	void printInfo(int&& t)
	{
		cout << "printInfo()参数类型为右值引用" << endl;
	}

	void printInfo(const int& t)
	{
		cout << "printInfo()参数类型为const左值引用" << endl;
	}

	template <typename T>
	void TestF(T&& t)
	{
		printInfo(std::forward<T>(t));
	}

}

namespace _nmsp3
{
	int getData()
	{
		return 3;
	}
	void funcLast(int v1)
	{
		cout << "funcLast, v1=" << v1 << endl;
	}

	void funcMiddle_Forward()
	{
		auto&& result = getData(); //getData返回的是右值，所以auto = int ,result = int &&（右值引用） 
		//....对result做各种运算。
		funcLast(std::forward<decltype(result)>(result));
	}

}

int main()
{ 
	_nmsp2::TestF(1);            //printInfo()参数类型为右值引用

	int i = 5;
	_nmsp2::TestF(i);            //printInfo()参数类型为左值引用
	_nmsp2::TestF(std::move(i)); //printInfo()参数类型为右值引用, std::move能够将左值转换成右值。

	const int j = 8;
	_nmsp2::TestF(j);            //printInfo()参数类型为const左值引用, j是个const左值
	_nmsp2::TestF(int(12));      //printInfo()参数类型为右值引用, int(12)是个临时对象，是个右值。

	int&& tempvalue = 16;
	_nmsp2::TestF(tempvalue);    //printInfo()参数类型为左值引用

	_nmsp3::funcLast(_nmsp3::getData());

	_nmsp3::funcMiddle_Forward();

	return 0;
}

