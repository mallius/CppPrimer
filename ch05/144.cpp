#include <iostream>
using namespace std;

class Sales_item {
public:

private:
	string book;
	double price;
	int num;
};

int main(void)
{
	Sales_item item, *p;
	cout << sizeof(Sales_item) << endl;
	cout << sizeof(item) << endl;
	cout << sizeof *p << endl;
	return 0;
}
