#include <iostream>
using namespace std;

class Base {
public:
	virtual int fcn() { cout << "Base fcn() " << endl; }  //虚函数
};

class D1 : public Base {
public:
	int fcn(int i) { cout << "D1 fcn()" << endl; }  //不是虚函数，原型不同
};

class D2 : public Base {
public:
	int fcn(int i) { cout << "D2 fcn(int) " << endl; }
	int fcn() { cout << "D2 fcn() " << endl; }		//是虚函数，重定义Base中
};

int main(void)
{
	Base bojb;
	D1 d1obj;
	D2 d2obj;
	Base *bojbP = &bojb, *d1objP = &d1obj, *d2objP = &d2obj; //基类指针
	bojbP->fcn();
	d1objP->fcn();
	d2objP->fcn();
}
