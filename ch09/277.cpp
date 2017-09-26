#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using std::string;
using std::vector;
using std::list;
using std::deque;
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	int array1[] = {1,2,3,4,5};
	int array2[] = {1,2,3,4};
	vector<int> ivec1(array1, array1+4);
	vector<int> ivec2(array2, array2+3);

	if(ivec1 > ivec2)
		cout << "ivec1 > ivec2" << endl;
	
	return 0;
}
