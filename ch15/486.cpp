#include <iostream>

using namespace std;

class Base{
	friend class Frnd;
public:
	Base(int val=0):i(val){}
protected:
	int i;
};

class Frnd{
public:
	int mem(Base b){return b.i;}
};

int main(void)
{
	Base b;
	Frnd f;
	cout << f.mem(b) << endl;
	return 0;
}
