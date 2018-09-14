#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

int main(void) 
{
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;
	vector<int> ivec(in_iter, eof);
	return 0;
}
