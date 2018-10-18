#include <iostream>

struct Sales_data {
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) {  }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main(void)
{
	return 0;
}
