#include <iostream>
using namespace std;

class Item_base{
public:
	Item_base(const std::string &book = "noname",
			double sales_price = 0.0): isbn(book), price(sales_price){ }
	std::string book() const { return isbn; }
	double get_price()const{return price;}
	void set_book(std::string &i){isbn = i;}
	virtual void set_price(double p){price = p;}
	virtual void set_book_price(std::string &i, double p){isbn = i; price = p;}
	virtual void set_book_price(const std::string &i, double p){isbn = i; price = p;}
	virtual double net_price(std::size_t n) const
				{return n * price;}
	virtual ~Item_base(){ }
private:
	std::string isbn;
protected:
	double price;
};

int main(void)
{
	Item_base i;
	cout << i.book() << endl;
	i.set_book_price("book1", 12.12);
	cout << i.book() << ", " << i.get_price() << endl;
	return 0;
}
