#include <iostream>

int main(void)
{
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0;
	decltype(cj) y = x;
	// decltype(cj) z;

	int i = 42, *p = &i, &r = i;
	decltype(r + 0) b;
	// decltype(*p) c;

	decltype(i) e;
	// decltype((i)) d;
	return 0;
}
