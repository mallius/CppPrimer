#include <iostream>
#include <vector>

using namespace std;

class Obj {
public:
	// Obj(): ival(0), kval(0), jval(0), vec() {  }
	int ival, kval, jval;
	vector<int> vec;
};

int main(void)
{
	Obj obj;
	Obj *ptr = &obj;
	if(ptr->ival != 0) //正确
		cout << "ival: " << ptr->ival << endl;
	if(ptr->ival != ptr->jval < ptr->kval)
		cout << "ival != jval < kval" << endl;
		
	return 0;
}
