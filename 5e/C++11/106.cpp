#include <iostream>

int main(void)
{
	int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *beg = std::begin(ia);
	int *last = std::end(ia);

	std::cout << *beg << std::endl;
	// std::cout << *last << std::endl;
	return 0;
}
