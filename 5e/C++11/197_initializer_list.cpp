#include <iostream>
#include <initializer_list>
using namespace std;

void error_msg(initializer_list<string> il)
{
	for(auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
}

int main(void)
{
	initializer_list<string> ls{"a", "b", "c"};
	error_msg(ls);
	error_msg({"functionX", "okay"});
	return 0;
}
