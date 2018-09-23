#include <iostream>
using namespace std;

struct Base {
	void foo(int i) { bar = i; }
protected:
	int bar;
	double foo_bar;
};

struct Derived : public Base {
	void foo(string s) { sbar = s; }
	bool bar(Base *pb) { return Base::foo_bar;  }
	void foobar() { Base::bar = 1024; }
private:
	string sbar;
};

int main(void)
{
	Base d; 
	d.foo(1024);
}
