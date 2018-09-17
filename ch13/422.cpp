#include <iostream>

using namespace std;

class U_Ptr{
	friend class HasPtr;
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p), use(1){}
	~U_Ptr(){delete ip;}
};

class HasPtr{
public:
	HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i){ }
	HasPtr(const HasPtr &orig): 
		ptr(orig.ptr), val(orig.val){++ptr->use;}
	HasPtr& operator=(const HasPtr&);
	~HasPtr(){if(--ptr->use==0)delete ptr;}  // delete栈上的地址是错的

	int *get_ptr()const{return ptr->ip;}
	int get_int()const{return val;}
	void set_ptr(int *p){ptr->ip = p;}
	void set_int(int i){val = i;}
	int get_ptr_val() const { return *ptr->ip; }
	void set_ptr_val(int i){*ptr->ip = i;}
private:
	U_Ptr *ptr;
	int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++rhs.ptr->use;
	if(--ptr->use==0)
		delete ptr;
	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}

int main(void)
{
	//不能写成int obj = 1; HasPtr ptr(&obj, 42)会运行崩溃
	//~HasPtr析构时delete栈上的地址会崩溃
	int *obj= new int(1); 
	HasPtr ptr1(obj, 42);
	HasPtr ptr2(ptr1);

	cout << ptr1.get_ptr_val() << endl;
	cout << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << endl;
	cout << ptr2.get_int() << endl;



	return 0;
}
