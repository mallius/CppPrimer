#include <iostream>

using namespace std;

class HasPtr{
public:
	HasPtr():val(0){ptr = new int;};
	HasPtr(const int &p, int i): ptr(new int(p)), val(i){}
	HasPtr(const HasPtr &orig):
		ptr(new int (*orig.ptr)), val(orig.val){}
	HasPtr& operator=(const HasPtr&);
	~HasPtr(){ delete ptr; }
	int get_ptr_val()const{return *ptr;}
	int get_int()const{return val;}
	void set_ptr(int *p){ptr=p;}
	void set_int(int i){val=i;}
	int *get_ptr()const{return ptr;}
	void set_ptr_val(int p)const{*ptr=p;}
private:
	int *ptr;
	int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	*ptr = *rhs.ptr;
	val = rhs.val;
	return *this;
}

int main(void)
{
	int n = 42;
	int n1= 11;

	HasPtr p(n, 1);	
	cout << p.get_ptr_val() << endl;
	p.set_int(n1);
	cout << p.get_int() << endl;
	p.set_ptr_val(10); 
	cout << p.get_ptr_val() << endl;

	HasPtr p1;
	p1 = p;
	cout << "p1:" << endl;
	cout << p1.get_ptr_val() << endl;
	cout << p1.get_int() << endl;
}



