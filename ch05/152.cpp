#include <iostream>
using namespace std;

int main(void)
{
	int i;
	int *pi = &i;
	// delete pi;  //错误但能编译通过
	
	string str = "dwarves";
	// delete str; //错误但不能编译通过
	int *ip = 0;
	delete ip;
	ip = NULL;

	const int *pci = new const int(1024);
	const string *pcs = new const string;

	delete pci;
	delete pcs;
	pci = 0;
	pcs = 0;

	return 0;
}
