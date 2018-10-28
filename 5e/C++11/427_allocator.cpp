#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
	int n = 10;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	auto q = p;
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c');
	alloc.construct(q++, "hi");

	while(q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, 'n');
	return 0;
}
