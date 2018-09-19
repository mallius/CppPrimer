#include <iostream>
using namespace std;

class Base {
public:
	std::size_t size() const { return n; }
protected:
	std::size_t n;
};

class Derived : private Base {
public:
	using Base::size;
protected:
	using Base::n;
};

class D : public Derived {
public:
	std::size_t D_size() const { return size(); }
};

int main(void)
{

}
