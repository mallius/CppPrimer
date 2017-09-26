#include <map>
#include <iostream>

using namespace std;

int main(void)
{
	multimap<string, string> books;
	books.insert(make_pair("Alan", "Book1"));
	books.insert(make_pair("Alan", "Book2"));
	books.insert(make_pair("Alan", "Book3"));
	books.insert(make_pair("Alan", "Book4"));
	books.insert(make_pair("Blan", "Book1"));
	books.insert(make_pair("Clan", "Book1"));
	books.insert(make_pair("Clan", "Book1"));
	books.insert(make_pair("Clan", "Book1"));

	string search_item("Alan");
	multimap<string, string>::iterator beg = books.lower_bound(search_item), 
		end = books.upper_bound(search_item);

	if(beg != end)
	{
		books.erase(beg, end);
	}


	search_item = "Clan";
	pair< multimap<string, string>::iterator, multimap<string, string>::iterator >  pos = 
		books.equal_range(search_item);
	if(pos.first != pos.second)
	{
		books.erase(pos.first, pos.second);
	}

	cout << "删除后遍历multimap: " << endl;
	for(multimap<string, string>::iterator it = books.begin(); it != books.end(); ++it)
	{
		cout << it->first << " ," << it->second << endl;
	}

	return 0;
}
