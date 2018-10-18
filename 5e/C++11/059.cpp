#include <iostream>

constexpr int new_sz() { return 42; }

int main(void)
{
	constexpr int mf = 20;
	constexpr int limit = mf + 1;
	constexpr int *q = nullptr;
	constexpr int foo = new_sz();
	return 0;
}
