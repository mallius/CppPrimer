#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
	vector<string> books;
	set<string> read;
	books.push_back("book1");
	books.push_back("book2");
	books.push_back("book3");
	books.push_back("book4");
	books.push_back("book5");

	read.insert("book2");
	read.insert("book5");

	cout << "Read books: " << endl;
	for(set<string>::iterator it = read.begin(); it != read.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "has not read books: " << endl;
	for(vector<string>::iterator it = books.begin(); it != books.end(); ++it)
	{
		if(read.count(*it))
			continue;
		cout << *it << endl;
	}
}
