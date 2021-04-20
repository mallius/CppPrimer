#include <iostream>
using namespace std;

namespace _nmsp1
{
	void funcLastVal(int v1, int v2)
	{
		++v2;					//改变v2的值，让其自增1
		cout << v1 + v2 << endl;
	}

	void funcLastLeftRefVal(int v1, int& v2)
	{
		++v2; //改变v2的值，让其自增1
		cout << v1 + v2 << endl;
	}

	void funcRightLeft(int&& v1, int& v2)
	{
		cout << v1 << endl;
		cout << v2 << endl;
	}

	template<typename F, typename T1,typename T2>
	void funcMiddle_Temp_Val(F f, T1 t1, T2 t2) //f:函数指针类型void(*)(int,int)，而funcLast是函数类型void(int,int)
	{
		f(t1, t2);
	}
	
	//函数模板（跳板函数）：把收到的参数以及这些参数相对应的类型不变的转发给其他函数（完美转发）
	template<typename F, typename T1,typename T2>
	void funcMiddle_Temp_UniRef(F f, T1&& t1, T2&& t2)
	{
		f(t1, t2);
	}
}

int main()
{ 
	//1
	int i = 50;
	_nmsp1::funcLastVal(40, i);                               //变量i自加1后 + 50 = 92
	cout << "funcLastVal, i=" << i << endl;                   //i为50

	int j = 60;
	_nmsp1::funcMiddle_Temp_Val(_nmsp1::funcLastVal, 20, j);  //变量j自加1后 + 20 = 91
	cout << "funcMiddle_Temp_Val, j=" << j << endl;

	int k = 50;
	_nmsp1::funcLastLeftRefVal(40, k);                        //直接调用，92,执行完k=51         
	cout << "funcLastLeftRefVal, k=" << k << endl;

	//2
	//91,执行完本函数，l = 71？70呢？ = 70
	//当前情况下l被funcMiddle_Temp_Val推断成了int而不是int&
	//void funcMiddle_Temp_Val(void(*f)(int,int &),int t1,int t2){...}
	int l = 70;
	_nmsp1::funcMiddle_Temp_Val(_nmsp1::funcLastLeftRefVal, 20, l); 
	cout << "funcMiddle_Temp_Val, l=" << l << endl;

	//91,T1=int, t1 = int &&，      T2 = int & , t2 = int &
    //m = 71;
	int m = 70;
	_nmsp1::funcMiddle_Temp_UniRef(_nmsp1::funcLastLeftRefVal, 20, m);  
	cout << "funcMiddle_Temp_UniRef, m=" << m << endl;
	
	//3
	int n = 70;
	_nmsp1::funcRightLeft(20, n); //20,70
	//20->t1(int &&)，但是t1本身是左值。
	//_nmsp1::funcMiddle_Temp_UniRef(_nmsp1::funcRightLeft, 20, n);

	int&& abc = 1;
	abc = 15;

	return 0;
}

