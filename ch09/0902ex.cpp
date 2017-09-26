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
	vector<string> svec1;
	vector<string> svec2(10);
	vector<string> svec3(10, "hello");
	vector<string> svec4(svec3);

	return 0;
}
