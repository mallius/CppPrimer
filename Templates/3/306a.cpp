#include <iostream>

//#include <boost/type_index.hpp>
using namespace std;
#pragma warning(disable : 4996)

namespace _nmsp1
{
	class Human
	{
	public:
		/*
		//构造函数
		Human(const string& tmpname) :m_sname(tmpname)
		{
			cout << "Human(const string &tmpname)执行" << endl;
		}

		//Human(string&& tmpname) :m_sname(tmpname)
		Human(string&& tmpname) :m_sname(std::move(tmpname)) //move并不具备移动能力，把一个左值转换成一个右值。
		{
			cout << "Human(string&& tmpname)执行" << endl;
		}
		*/

		//构造函数模板
		template<typename T>
		Human(T&& tmpname) : m_sname(std::forward<T>(tmpname))
		{
			cout << "Human(T&& tmpname)构造函数模板执行" << endl;
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
}


int main()
{

	string sname = "ZhangSan";
	_nmsp1::Human myhuman1(sname);
	_nmsp1::Human myhuman2(string("LiSi"));         //"LiSi"是const char[5]类型，而string("LiSi")是string类型。

	//_nmsp1::Human myhuman3(myhuman1);             //实际编译器去调用了构造函数模板，而不是调用了拷贝构造函数。 std::enable_if
	_nmsp1::Human myhuman4(std::move(myhuman1));

	const _nmsp1::Human myhuman5(string("WangWu"));
	_nmsp1::Human myhuman6(myhuman5);

	return 0;
}

