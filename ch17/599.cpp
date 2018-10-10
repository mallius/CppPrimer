#include <iostream>

namespace cplusplus_primer {
	class Sales_item {

	};

	class Query {

	};
}
namespace AddisonWesley {
	class Query {
	public:
		void display() const { std::cout << "AddisonWesley::Query.display" << std::endl; }

	};
}
int main(void)
{
	using AddisonWesley::Query;

	cplusplus_primer::Sales_item s;
	cplusplus_primer::Query q;
	Query qa;
	qa.display();

	return 0;
}
