#include <iostream>
using namespace std;

struct ConcreteBase {
	static std::size_t object_count() { cout << "object_count" << endl; }
protected:
	static std::size_t obj_count;
};

struct C1 : public ConcreteBase {
	void f(const C1& c1);
};

void C1::f(const C1& c1)
{
	ConcreteBase::object_count();
	C1::object_count();
	c1.object_count;
	object_count();
}

int main(void)
{
	C1 c1;
	c1.f(c1);
}
