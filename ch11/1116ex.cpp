#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) 
{
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;
	ostream_iterator<int> out_iter(cout, ",");
	vector<int> ivec(in_iter, eof);

	copy(ivec.begin(), ivec.end(), out_iter);
	
	return 0;
}
