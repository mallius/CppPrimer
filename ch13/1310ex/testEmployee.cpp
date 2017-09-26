#include "Employee.h"

int main(void)
{
	Employee emp1;
	emp1.show();

	Employee emp2;
	emp2.show();

	Employee emp3 = emp2;
	emp3.show();

	Employee emp4("John");
	emp4.show();
}
