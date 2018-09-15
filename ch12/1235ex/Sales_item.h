#include <string>
#include <iostream>
using namespace std;

class Sales_item
{
public:
	friend Sales_item add(const Sales_item&, const Sales_item&);
	friend void input(std::istream& is, Sales_item& s);

	bool same_isbn(const Sales_item &rhs)const 
	{
		return isbn == rhs.isbn;
	}
	// 构造函数
	Sales_item(const std::string &book = ""): isbn(book), units_sold(0), revenue(0)
	{

	}
	Sales_item(std::istream &is)
	{
		cin >> isbn >> units_sold >> revenue;
	}
	void show()const 
	{
		cout << "isbn: " << isbn << endl;
		cout << "units_sold: " << units_sold << endl;
		cout << "revenue: " << revenue << endl;
	}
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

Sales_item add(const Sales_item& s1, const Sales_item& s2)
{
	if(s1.same_isbn(s2))
		return s1;
	Sales_item temp;
	temp.isbn = s1.isbn;
	temp.units_sold = s1.units_sold + s2.units_sold;
	temp.revenue = s1.revenue + s2.revenue;
	return temp;
}

void input(std::istream& is, Sales_item& s)
{
	cout << "Enter: abc 1 1.23 " << endl;
	is >> s.isbn >> s.units_sold >> s.revenue;	
}
