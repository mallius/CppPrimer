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


	typedef pair< multimap<string, string>::iterator, multimap<string, string>::iterator > Iter;
	string search_item = "Alan";
	cout << "Alan, ";
	Iter  pos = books.equal_range(search_item);
	while(pos.first != pos.second)
	{
		cout << pos.first->second << ", ";
		++pos.first;
	}
	cout << endl;

	search_item = "Blan";
	cout << "Blan, ";
	pos = books.equal_range(search_item);
	while(pos.first != pos.second)
	{
		cout << pos.first->second << ", ";
		++pos.first;
	}
	cout << endl;

	search_item = "Clan";
	cout << "Clan, ";
	pos = books.equal_range(search_item);
	while(pos.first != pos.second)
	{
		cout << pos.first->second << ", ";
		++pos.first;
	}
	cout << endl;

	return 0;
}
