#include <memory>
using namespace std;

void f()
{
	auto_ptr<int> ap(new int(42));
}

int main(void)
{
	f();
	auto_ptr<int> pi = new int(1024);
	return 0;
}
