#include <string>
using namespace std;

class Foo {

};

void fcn()
{

}


template <class T> 
class Foo2 {

};

template <class T> 
void templ_fcn2(const T& t)
{

}

template <class T> 
class Foo3 {

};

template <class T> 
void templ_fcn3(const T& t)
{

}

template <class Type> class Bar {
	friend class Foo;								// 普通类是类模板的友元
	friend void fcn();								// 普通函数是类模板的友元

	template <class T> friend class Foo2;                   //类模板的所有实例是另一个类模板的友元(T和Type)不同
	template <class T> friend void templ_fcn2(const T& t);  // 函数模板的所有实例是类模板的友元

	friend class Foo3<Type>;						// 类模板特定实例是另一个类模板的友元（都是Type）
	friend void templ_fcn3<Type>(const Type& t);	// 函数模板特定实例是类模板的友元（都是Type）

	//
};

int main(void)
{
	Bar<int> bi;
	Bar<string> bs;
}
