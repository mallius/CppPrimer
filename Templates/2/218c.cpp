/***
第六节 模板的一些特殊继承关系说
（1）奇异（奇特）的递归模板模式（CRTP）:Curiously Recurring  Template Pattern。是一种模板编程手法：把派生类作为基类的模板参数：
（1.1）在基类中使用派生类对象
（1.2）基于减少派生类中代码量的考虑:出发点是尽可能把一些代码挪到基类中，从而有效的减少派生类中的代码量；
（1.3）基类调用派生类的接口与多态的体现(静态多态编程技术)
***/

#include <iostream>
using namespace std;

//(1.3)基类调用派生类的接口与多态的体现(静态多态编程技术)
namespace _nmsp3
{
	//基类模板
	template <typename T>
	class Human
	{
	public:
		T& toChild()
		{
			return static_cast<T&>(*this);
		}
		void parenteat()
		{
			toChild().eat(); //派生类给基类提供了调用接口
		}

	private:
		Human() {};
		friend T; //T派生类变成了友元类		
	};

	//子类继承基类模板,且基类模板中传入子类
	class Men :public Human<Men>
	{
	public:
		void eat()
		{
			cout << "Men,eat" << endl;
		}
	};
	
	//子类继承基类模板,且基类模板中传入子类
	class Women :public Human<Women>
	{
	public:
		void eat()
		{
			cout << "Women,eat" << endl;
		}
	};

	template<typename T>
	void myHumanFuncTest(Human<T>& tmpobj)
	{
		tmpobj.parenteat();
	}
}

int main()
{
	_nmsp3::Men mymen;
	_nmsp3::Women mywomen;

	mymen.parenteat();
	mywomen.parenteat();
	
	_nmsp3::myHumanFuncTest(mymen);
	_nmsp3::myHumanFuncTest(mywomen);


	return 0;
}
