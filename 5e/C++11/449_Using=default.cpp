#include <iostream>

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const Sales_data&) = default;
	Sales_data& operator=(const Sales_data&);
	~Sales_data() = default;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::operator=(const Sales_data&) = default;

struct NoCopy {
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;
	NoCopy& operator=(const NoCopy&) = delete;
	~NoCopy() = default;
};

struct NoDtor {
	NoDtor() = default;
	~NoDtor() = delete;
};

int main(void)
{
	Sales_data s;
	// NoDtor nd;
	NoDtor *p = new NoDtor();
	// delete p;

	return 0;
}
