#include <iostream>

using namespace std;

namespace _nmsp2
{
	//目标函数
	int funcTarget(int v1, int& v2) 
	{
		//改变v2的值，让其自增1
		++v2;             
		cout << v1 + v2 << endl;
		return v1 + v2;
	}

	/*
	template<typename F, typename T1,typename T2>	
	void funcMiddle_Temp(F f, T1&& t1, T2&& t2)  //转发函数
	{		
		f(
			std::forward<T1>(t1),
			std::forward<T2>(t2) 
		);
	}
	*/

	/*
	//支持任意数量、类型参数的完美转发
	template <typename F, typename...T>
	void funcMiddle_Temp(F f, T&&... t)
	{
		f(std::forward<T>(t)...);
	}
	*/

	template <typename F, typename...T>
	auto funcMiddle_Temp(F f, T&&... t)->decltype(f(std::forward<T>(t)...))
	//decltype(auto) funcMiddle_Temp(F f, T&&... t)  //C++14
	{
		return f(std::forward<T>(t)...);
	}

}

int main()
{ 
	int i = 70;
	_nmsp2::funcMiddle_Temp(_nmsp2::funcTarget, 20, i);
	cout << "i = " << i << endl;
	
	int j = 70;
	int k = _nmsp2::funcMiddle_Temp(_nmsp2::funcTarget, 20, j);
	cout << "j = " << j << endl;
	cout << "k = " << k << endl;
		
	return 0;
}

