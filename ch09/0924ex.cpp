#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;
int main(void)
{
	int array[] = {1,2,3};
	vector<int> iv(array, array+2);
	vector<int>::reference val = iv.front();
	vector<int>::reference val2 = *iv.begin();
	vector<int>::reference val3 = iv.at(0);
	vector<int>::reference val4 = iv[0];

	cout << val << endl;
	cout << val2 << endl;
	cout << val3 << endl;
	cout << val4 << endl;
	
	return 0;
}
