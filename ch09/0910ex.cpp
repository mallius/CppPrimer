#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using std::string;
using std::vector;
using std::list;
using std::deque;


int main(void)
{
	const vector< int > ivec(10);
	vector<int>::const_iterator it = ivec.begin();
	return 0;
}
