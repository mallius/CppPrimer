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

}

int main()
{   
	//利用boost输出类型名比typeid(...).name()用法输出类型名更准确。
	using boost::typeindex::type_id_with_cvr;

	//这里注意不要把std::declval<_nmsp1::A>后面的圆括号对丢掉,
	//否则代码含义就发生变化了。想象函数调用时即便没有参数也要把圆括号带着。
	using YT = decltype(std::declval<_nmsp1::A>()); 
	cout << "YT=" << type_id_with_cvr<YT>().pretty_name() << endl; //显示YT的类型

    //必须为构造函数提供参数
	//_nmsp1::A myaobj(1); 
	//cout << "myaobj.myfunc()的返回类型=" << type_id_with_cvr<decltype(myaobj.myfunc())>().pretty_name() << endl;

	//无需构造函数
	cout << "A::myfunc()的返回类型=" << type_id_with_cvr<decltype(std::declval<_nmsp1::A>().myfunc())>().pretty_name() << endl;

    //看起来是一个函数声明的语法，该函数返回的类型是A&&，可以看成是返回了一个A&&类型的对象，这种对象就可以看成是类A对象。
	_nmsp1::A&& refobj(); 
    //refobj();           //error,看起来是调用refobj这个函数
    //refobj().myfunc();  //error
	decltype(refobj().myfunc()) dvar = 1.2; //定义了一个double类型的变量dvar;
	cout << dvar << endl;

	return 0;
}

