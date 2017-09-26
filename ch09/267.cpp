#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using std::string;
using std::vector;
using std::list;
using std::deque;

class Foo
{
private:
	int data;
public:
	Foo(){};
	Foo(int i){data = i;}
	Foo(const Foo& f){data = f.data;}
};

int main(void)
{
	vector<Foo> empty;		//Foo()
	vector<Foo> bad(10);	//Foo()
	
	vector<Foo> ok(10, 1);  //Foo(int i)
	return 0;
}
