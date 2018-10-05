#include <iostream>
using namespace std;

template <class T> class Foo {
public:
	static std::size_t count() { return ctr; }
private:
	static std::size_t ctr;
};

