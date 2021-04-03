/***
第六节 模板的一些特殊继承关系说
（1）奇异（奇特）的递归模板模式（CRTP）:Curiously Recurring  Template Pattern。是一种模板编程手法：把派生类作为基类的模板参数：
（1.1）在基类中使用派生类对象
（1.2）基于减少派生类中代码量的考虑:出发点是尽可能把一些代码挪到基类中，从而有效的减少派生类中的代码量；
（1.3）基类调用派生类的接口与多态的体现(静态多态编程技术)
***/

#include <iostream>
using namespace std;

//(1.2)基于减少派生类中代码量的考虑:出发点是尽可能把一些代码挪到基类中,从而有效的减少派生类中的代码量
namespace _nmsp2
{
	//基类模板
	template<typename T>
	struct shape
	{
		//把派生类对象是否相等的判断挪到了基类中(使用了在类模板中定义友元函数的手段把全局的operator==放到基类中)
		friend bool operator==(const shape<T>& obj1, const shape<T>& obj2) //在类模板中定义友元
		{
			const T& objtmp1 = static_cast<const T&>(obj1);                //派生类对象也是基类对象,所以这种静态类型转换没问题
			const T& objtmp2 = static_cast<const T&>(obj2);
			if (!(objtmp1 < objtmp2) && !(objtmp2 < objtmp1))
				return true;
			return false;
		}
	};
	
	/**
	template<typename T>
	bool operator==(const shape<T>& obj1, const shape<T>& obj2)
	{
		const T& objtmp1 = static_cast<const T&>(obj1);
		const T& objtmp2 = static_cast<const T&>(obj2);
		if (!(objtmp1 < objtmp2) && !(objtmp2 < objtmp1))
			return true;
		return false;
	}
	**/

	//派生类
	struct square : public shape<square>
	{
		int sidelength; //边长
	};

	//类外运算符重载
	bool operator<(square const& obj1, square const& obj2)
	{
		if (obj1.sidelength < obj2.sidelength)
		{
			return true;
		}
		return false;
	}


}

int main()
{
	_nmsp2::square objsq1;    //派生类对象
	objsq1.sidelength = 15;
	
	_nmsp2::square objsq2;
	objsq2.sidelength = 20;   //派生类对象
	
	if (!(objsq1 == objsq2))
	{
		cout << "objsq1和objsq2不相等!" << endl;
	}
	else
	{
		cout << "objsq1和objsq2相等!" << endl;
	}
	
	return 0;
}
