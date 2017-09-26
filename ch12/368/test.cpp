#include "Sales_item.h"
#include <iostream>

int main(void)
{
	Sales_item si;
	double av = si.avg_price();
	std::cout << av << std::endl;
	return 0;
}
