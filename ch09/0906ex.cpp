#include <list>

using std::list;

class Foo
{
private:
	int data;
public:
	Foo(int i){data = i;}
};

int main(void)
{
	int num = 100;
	list<Foo> FooList(10, num);
	return 0;
}
