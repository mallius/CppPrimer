#include <iostream>
using namespace std;

char *string_copy(char *s) { }

int main(void)
{
	const char *pc_str;
	// char *pc = string_copy(pc_str);
	char *pc = string_copy(const_cast<char*>(pc_str));

	double d = 97.0;
	char ch = static_cast<char>(d);

	void *p = &d;
	double *dp = static_cast<double*>(p);

	return 0;
}
