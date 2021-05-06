/***
（3）enable_if
1. 基础认识:C++11新标准中引入的类模板（结构模板）。使用体现了C++编译器的SFINAE特性。
定位为一个helper模板（助手模板），用于辅助其他模板的设计，表现一种：编译器的分支逻辑（编译期就可以确定走哪条分支）。
偏特化完全可以理解成一种条件分支语句。
2. 范例：enable_if用于函数模板中：典型应用是作为函数模板的返回类型。
3. 范例：enable_if用于类模板中
_nmsp3::Human myhuman3(myhuman1);代码行解决办法：针对构造函数模板，如果给进来的参数是一个string类型的参数，就让这个构造函数模板生效。
否则就让这个构造函数模板被忽略即可。也就是说，如果使用enable_if于构造函数模板中，enable_if的条件只需要设置成“形参类型==string类型”即可。
std::is_convertible，C++11一如。两个模板参数分别是From 和To：用于判断能否从某个类型隐式的转换到另外一个类型。返回一个bool值——true或者false。
***/

#include <iostream>
#include <vector>

using namespace std;

namespace _nmsp1
{	
	template <typename T>
	struct MEB
	{
		using type = T;
	};

	//泛化版本
	//no member "type" when !_Test
	//STRUCT TEMPLATE enable_if
	template <bool _Test, class _Ty = void>   
	struct Enable_If {};                      

	//偏特化版本:怎么理解：只有这个偏特化版本存在，才存在一个名字叫做type的类型别名（类型）
	//type is _Ty for _Test
	template <class _Ty>                      
	struct Enable_If<true, _Ty> {             
		using type = _Ty;
	};
}


int main()
{ 
	_nmsp1::MEB<int>::type ia = 15;            //_nmsp1::MEB<int>::type就代表int类型
	cout << ia << endl;
	_nmsp1::MEB<double>::type da = 15.1;
	cout << da << endl;

	return 0;
}





























/*

class Human
{
public:
	////构造函数
	//Human(const string& tmpname) :m_sname(tmpname)
	//{
	//	cout << "Human(const string &tmpname)执行" << endl;
	//}
	////Human(string&& tmpname) :m_sname(tmpname)
	//Human(string&& tmpname) :m_sname(std::move(tmpname)) //move并不具备移动能力，把一个左值转换成一个右值。
	//{
	//	cout << "Human(string&& tmpname)执行" << endl;
	//}

	//构造函数模板
	template<typename T>
	Human(T&& tmpname) : m_sname(std::forward<T>(tmpname))
	{
		cout << "Human(T&& tmpname)执行" << endl;
	}

	//拷贝构造函数
	Human(const Human& th) : m_sname(th.m_sname)
	{
		cout << "Human(const Human& th)拷贝构造函数执行" << endl;
	}

	//移动构造函数
	Human(Human&& th) : m_sname(std::move(th.m_sname))
	{
		cout << "Human(Human&& th)移动构造函数执行" << endl;
	}

private:
	string m_sname;
};

*/


/*

string sname = "ZhangSan";
_nmsp1::Human myhuman1(sname);
_nmsp1::Human myhuman3(myhuman1); //实际编译器去调用了构造函数模板，而不是调用了拷贝构造函数。

*/
