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

	for(multimap<string, string>::iterator it = books.begin(); it != books.end(); ++it)
	{
		cout << it->first << " ," << it->second << endl;
	}
	string search_item("Clan");
	multimap<string, string>::size_type sz = books.count(search_item);
	cout << "found: " << sz << endl;
	// 删除
	books.erase(search_item);
	for(multimap<string, string>::iterator it = books.begin(); it != books.end(); ++it)
	{
		cout << it->first << " ," << it->second << endl;
	}

	return 0;
}
