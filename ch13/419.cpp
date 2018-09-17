#include <iostream>
using namespace std;

class HasPtr{
public:
	HasPtr(int *p, int i): ptr(p), val(i){}  //直接复制指针会有潜在的问题
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
	cout << ptr2.get_int() << endl;
	cout << ptr1.get_int() << endl;

	ptr1.set_ptr_val(42);  //设置了ptr1, ptr2也改变了
	cout << ptr2.get_ptr_val() << endl;

	int *ip = new int(42);
	HasPtr ptr(ip, 10);
	delete ip;  // ip指向的内容释放, 还给ip指向的内容赋值
	ptr.set_ptr_val(101); //disaster: The object to which HasPtr points was freed!
	cout << ptr.get_ptr_val() << endl;  //竟然还能赋值成功
	
	return 0;
}
