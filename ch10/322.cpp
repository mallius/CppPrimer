#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int main(void)
{
	// 元素的添加和删除
	multimap<string, string> authors;
	authors.insert(make_pair(string("Barth, John"), string("Sot-Weed Factor")));

	authors.insert(make_pair(string("Barth, John"), string("Lost in the Funhouse")));
	
	string search_item("Lost in the Funhouse");
	multimap<string, string>::size_type cnt = authors.erase(search_item);

	typedef multimap<string, string>::size_type sz_type;
	string search_item2("Sot-Weed Factor");
	sz_type entries = authors.count(search_item2);
	//cout << sz_type << endl;

	multimap<string, string>::iterator iter = authors.find(search_item2);
	for(sz_type cnt = 0; cnt != entries; ++cnt, ++iter)
		cout << iter->second << endl;
	
	typedef multimap<string, string>::iterator authors_it;
	authors_it beg = authors.lower_bound(search_item),
			   end = authors.upper_bound(search_item);

	while(beg != end)
	{
		cout << beg->second << endl;	
		++beg;
	}
	
		
	return 0;
}
