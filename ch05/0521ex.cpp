#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int ia[] = {1, 2, 3};
	vector<int> ivec(ia, ia+3);
	for(int i = 0; i < ivec.size(); ++i)
	{
		ivec[i]%2==0 ? ivec[i] : ivec[i] = 2*ivec[i];	
	}
	
	for(int i = 0; i < ivec.size(); ++i)
	{
		cout << ivec[i] << endl;
	}
	return 0;
}
