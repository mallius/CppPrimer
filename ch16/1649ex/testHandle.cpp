#include "SalesItem.h"

int main(void)
{
	Handle<int> hp(new int(42));

	Handle<int> hp2 = hp;
	cout << *hp << " " << *hp2 << endl;
	*hp2 = 0;

	cout << *hp << endl;
	return 0;
}
