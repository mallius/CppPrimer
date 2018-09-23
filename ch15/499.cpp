#include <iostream>
using namespace std;

struct Base {
	Base() : mem(0) {  }	
protected:
	int mem;
};

struct Derived : Base {
	Derived(int i) : mem(i) {  }
	int get_mem() { return Base::mem; } 
protected:
	int mem;
};

int main(void)
{
	Derived d(42);
	cout << d.get_mem() << endl;
	return 0;
}
