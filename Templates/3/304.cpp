/***
第三节 完美转发
（1）完美转发的概念和步骤演绎
a)直接调用：  funcLast();
b)转发： 通过funcMiddle()间接调用funcLast。funcMiddle相当于一个跳板函数。如果有参数，那么参数也需要通过funcMiddle中转传递给funcLast()
c)完美转发：const,左值，右值。实参的属性完全不丢失，原原本本的通过funcMiddle转发给funcLast，这种转发就是完美转发。

万能引用：实参的所有信息都会传递到万能引用当中去从而让编译器推导出来函数模板最终的形参类型 (引用折叠)。
完美转发：就是让开发者可以书写接受任意实参的函数模板（funcMiddle_Temp），并将其转发到目标函数（funcLast2)，目标函数会接收到与
转发函数（funcMiddle_Temp）所接收的完全相同（当然包括类型相同比如保持参数的左值、右值特性）的参数。
要实现完美转发，就要用到std::forward了。
***/

#include <iostream>

//#include <boost/type_index.hpp>
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
	//void funcLast(int v1, int v2)
	void funcLast(int v1, int& v2)
	{
		++v2; //改变v2的值，让其自增1
		cout << v1 + v2 << endl;
	}

	void funcLast2(int&& v1, int& v2)
	{
		cout << v1 << endl;
		cout << v2 << endl;
	}

	//函数模板（跳板函数）：把收到的参数以及这些参数相对应的类型不变的转发给其他函数（完美转发）
	template<typename F, typename T1,typename T2>
	//void funcMiddle_Temp(F f, T1 t1, T2 t2) //f:函数指针类型void(*)(int,int)，而funcLast是函数类型void(int,int)
	void funcMiddle_Temp(F f, T1&& t1, T2&& t2)
	{
		f(t1, t2);
	}
}

int main()
{ 
	/*
	int i = 50;
	_nmsp1::funcLast(41, i);                           //变量i自加1后 + 50 = 92
	*/

	/*
	int j = 70;
	_nmsp1::funcMiddle_Temp(_nmsp1::funcLast, 20, j);  //变量j自加1后 + 20 = 91
	*/

	/*
	int k = 50;
	_nmsp1::funcLast(41, k);                          //直接调用，92,执行完k=51         
	*/

	/*
	int l = 70;
	_nmsp1::funcMiddle_Temp(_nmsp1::funcLast, 20, l); //91,执行完本函数，l = 71？70呢？ = 70
	                                                  //当前情况下l被funcMiddle_Temp推断成了int而不是int&
	                                                  //void funcMiddle_Temp(void(*f)(int,int &),int t1,int t2){...}
	*/

	/*
	int m = 70;
	_nmsp1::funcMiddle_Temp(_nmsp1::funcLast, 20, m);  //91,T1=int, t1 = int &&，      T2 = int & , t2 = int &
		                                               //m = 71;
	*/
	
	int n = 70;
	//_nmsp1::funcLast2(20, n); //20,70
	_nmsp1::funcMiddle_Temp(_nmsp1::funcLast2, 20, n);
	                                                 //20->t1(int &&)，但是t1本身是左值。

	/*int&& abc = 1;
	abc = 15;*/

	return 0;
}

