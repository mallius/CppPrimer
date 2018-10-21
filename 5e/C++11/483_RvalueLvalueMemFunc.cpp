#include <iostream>
using namespace std;

class Foo {
public:
	Foo& operator=(const Foo&) &; //只能向可修改的左值赋值
};

Foo& Foo::operator=(const Foo& rhs) &
{
	return *this;
}

int main(void)
{
	return 0;
}
