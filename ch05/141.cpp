#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	char ia[] = {1, 2, 3, 4, 5};
	vector<int> ivec(ia, ia+5);
	vector<int>::iterator it = ivec.begin();
	while(it != ivec.end())
	{
		cout << *it++ << endl;
	}
	return 0;
}
