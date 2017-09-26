#include <iostream>
using namespace std;

class HasPtr{
public:
	HasPtr(int *p, int i): ptr(p), val(i){}
	int *get_ptr()const{return ptr;}
	int get_int()const{return val;}
	void set_ptr(int *p){ptr=p;}
	void set_int(int i){val = i;}
	int get_ptr_val()const{return *ptr;}
	void set_ptr_val(int val)const{*ptr=val;}
private:
	int *ptr;
	int val;
};

int main(void)
{
	int obj=0;
	HasPtr ptr1(&obj, 42);
	HasPtr ptr2(ptr1);
	
	ptr1.set_int(0);
	ptr2.get_int();
	ptr1.get_int();

	ptr1.set_ptr_val(42);
	ptr2.get_ptr_val();

	int *ip = new int(42);
	HasPtr ptr(ip, 10);
	delete ip;
	ptr.set_ptr_val(0); //disaster: The object to which HasPtr points was freed!
	
	return 0;
}
