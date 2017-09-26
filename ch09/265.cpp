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
	vector<string> svec;
	list<int> ilist;
	deque<int> items;

	vector<int> ivec;
	vector<int> ivec2(ivec);
	// list<int> ilist(ivec); error
	vector<double> dvec(ivec); 
}
