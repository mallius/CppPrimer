#include <iostream>
#include <memory>
#include <list>

using namespace std;

int main(void)
{
	shared_ptr<string> p1;
	shared_ptr<list<int>> p2;

	if(p1 && p1->empty())
		*p1 = "hi";

	return 0;
}
