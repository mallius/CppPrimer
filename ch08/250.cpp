#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int main(void)
{
	//1.输出缓冲区的刷新
	cout << "hi!" << flush;
	cout << "hi!" << ends;
	cout << "hi!" << endl;

	//2.unitbuf操纵符
	cout << unitbuf << "first" << "second" << nounitbuf;
	cout << "first" << flush << "second" << flush;
	return 0;
}
