#include <iostream>
using namespace std;

class Picture {
public:
	virtual void open() { cout << "Picture open" << endl; }
protected:
	int point;
};

class Gif : public Picture {
public:
	virtual void open() { cout << "Gif open, point: " << point << endl; }
};

int main(void)
{
	Gif g;
	g.open();

	return 0;
}
