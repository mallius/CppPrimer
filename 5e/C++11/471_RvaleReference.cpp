#include <iostream>
using namespace std;
int main(void)
{
	int i = 42;
	int &r = i;
	// int &&rr = i;
	// int &r2 = i * 42;
	const int &r3 = i * 42;  // const引用可以绑定到右值上
	int &&rr2 = i * 42;

	int &&rr1 = 42;
	// int &&rr3 = rr1;      // 表达式rr1是左值。变量是左值。
	int &&rr3 = std::move(rr1);

	return 0;
}
