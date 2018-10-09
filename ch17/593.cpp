#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
	auto_ptr<string> ap1(new string("Stegosaurus"));
	auto_ptr<string> ap2(ap1);
	cout << ap2->c_str() << endl;  //所有权转移到ap2

	auto_ptr<string> ap3(new string("Pterodacty1"));
	ap3 = ap2;
	cout << ap3->c_str() << endl;  

	//使用get成员
	auto_ptr<int> p_auto;
	if(p_auto.get())
		*p_auto = 1024;
	else 
		p_auto.reset(new int(1024));

	cout << *p_auto << endl;

	return 0;
}

