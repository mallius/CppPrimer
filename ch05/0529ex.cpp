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
	if(ptr->ival != ptr->jval < ptr->kval)  //正确
		cout << "ival != jval < kval" << endl;
	//if(ptr != 0 && *ptr++)  //错误
		//cout << "ptr != 0 && *ptr++" << endl;
	//ival++ && ival 有歧义 
	//vec[ival++] <= vec[ival] //有歧义
		
	return 0;
}
