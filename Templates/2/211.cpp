/***
第三节类模板中的友元
(1)友元类：
让某个类B称为另外一个类A的友元类，这样的话，类B就可以在其成员函数中访问类A的所有成员，
而不管这些成员在类A中是用什么（public,protected,private）来修饰的。
如果现在类A和类B都变成了类模板，那么能否让类模板B成为类模板A的友元类模板呢？
1.1：让类模板的某个实例成为友元类
1.2：让类模板成为友元类模板
1.3：让类型模板参数成为友元类:C++11新标准中引入：如果传递进来的类型模板参数是一个类类型，则这个类类型可以成为当前类模板的友元类。
a)代码行A2<CF> aobj1; 的效果是让CF类成为了A2<CF>类的友元类；
b)于是，在CF类的成员函数中，可以直接访问aobj1这个A2<CF>类对象的data私有成员变量。
如果传递给类模板A2的类型模板参数不是一个类类型，那么代码行friend T;就会被忽略。
***/

#include <iostream>

//#include <boost/type_index.hpp>
using namespace std;
//#pragma warning(disable : 4996)

namespace _nmsp1
{
	//template <typename U> class B;       //类模板B的声明

	template <typename T>
	class A
	{
		//friend class B<long>;            //不需要任何public,private等修饰符。
		template<typename> friend class B; //类模板B作为类模板A的友元
	private:
		int data;
	};

	template <typename U>
	class B
	{
	public:
		void callBAF()                     //在类模板B中访问类模板A的私有成员
		{
			A<int> atmpobj;
			atmpobj.data = 5;
			cout << atmpobj.data << endl;
		}
	};
}

namespace _nmsp2
{
	template <typename T>
	class A2
	{
		friend T;                       //类T成为类模板A2的友元
		friend  class CF;

	private:
		int data;
	};

	class CF
	{
	public:
		void callCFAF()
		{
			A2<CF> aobj1;                //让CF类成为了A2<CF>类的友元类
			aobj1.data = 12;
			cout << aobj1.data << endl;

			A2<int> aobj2;               //因为CF类并不是A2<int>的友元类，自然不能在这里访问aobj2这个A2<int>类对象的data私有成员变量。
			aobj2.data = 15;
			cout << aobj2.data << endl;
		}
	};
}

int main()
{
	//测试nmsp1
	//_nmsp1::B<long> bobj;
	_nmsp1::B<int> bobj;
	bobj.callBAF();

	//测试nmsp2
	_nmsp2::CF mycfobj;
	mycfobj.callCFAF();

	/*_nmsp2::A2<_nmsp2::CF> aobj1;
	aobj1.data = 12;*/

	return 0;
}
