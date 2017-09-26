#include <iostream>

using namespace std;

class exmp
{
private: 
	string str;
public:
	exmp(){cout << "exmp()" << endl;};
	exmp(const exmp&){cout << "exmp(const exmp&)" << endl;};
	exmp(string& s){cout << "exmp(string& s)" << endl;};
	exmp(const string& s){cout << "exmp(const string&)" << endl;};
	exmp& operator=(const exmp& e){str = e.str;cout << "operator=" << endl;};	
	~exmp(){cout << "~exmp()" << endl;};
};

int main(void)
{
	cout << "p:" << endl;
	exmp *p = new exmp();
	delete p;

	cout << "e1:" << endl;
	exmp e1;

	cout << "e2:" << endl;
	exmp e2("Hell");

	cout << "e3:" <<endl;
	string str = "Word";
	exmp e3(str);

	cout << "e4:" << endl;
	exmp e4 = e3;

	cout << "e5:" << endl;
	exmp e5;
	e5 = e3;

	return 0;
}
