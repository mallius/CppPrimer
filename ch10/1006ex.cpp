#include <string>
#include <list>
#include <map>
#include <vector>

using std::string;
using std::list;
using std::map;
using std::vector;
int main(void)
{
	map<vector<int>::iterator, int> a;
	map<list<int>::iterator, int> b;
	//map<pair<int,string>, int> c;  //pair<int,string>不支持<符号
	return 0;
}
