#include <iostream>

template <class T, size_t N> void array_init(T (&parm)[N])  //数组的引用
{
	for(size_t i = 0; i != N; ++i) {
		parm[i] = 0;
	}
}

int main(void)
{
	int x[42];
	double y[10];
	array_init(x);
	array_init(y);

	const int sz = 40;
	int z[sz + 2];
	array_init(z);
}
