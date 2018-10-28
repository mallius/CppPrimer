#include <iostream>
using namespace std;
class cls {  };

int main(void)
{
	/*int i;
	int *pi = new int;
	delete pi;
	*/

	int i(1024); 
	int *pi = new int(1024);
	cout << *pi << endl;
	delete pi;

	string s(10, '9');
	string *ps = new string(10, '9');
	cout << *ps << endl;
	delete ps;

	cls *pc = new cls();
	delete pc; 

	return 0;
}
