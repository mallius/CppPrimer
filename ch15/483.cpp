#include <iostream>

using namespace std;

class Base {
public:
	void basemem() {  }
protected:
	int i;
};

struct Public_derived : public Base {
	int use_base() { return i; }
};

struct Private_derived : private Base {
	int use_base() { return i; }
};

int main(void)
{
	Base b;
	Public_derived d1;
	Private_derived d2;
	b.basemem();
	d1.basemem();
	// d2.basemem();  私有继承无法访问基类
	return 0;
}
