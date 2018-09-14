#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vec;
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;

	while(in_iter != eof)
	{
		vec.push_back(*in_iter++);	
	}
	for(vector<int>::const_iterator it = vec.begin();
			it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
