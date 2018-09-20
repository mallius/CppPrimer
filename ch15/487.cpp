#include <iostream>
using namespace std;

class Base{
public:
	static void statmem() {  };   //struct默认public
};

class Derived : public Base{
public:
	void f(int i);
};

void Derived::f(int i)
{
	// 4种方法
	Base::statmem();
	Derived::statmem();
}

int main(void)
{

}
