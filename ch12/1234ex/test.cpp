#include "Sales_item.h"


int main(void)
{
	Sales_item d1("112");
	Sales_item d2("113");
	Sales_item d3 = add(d1, d2);
	d3.show();

	return 0;
}
