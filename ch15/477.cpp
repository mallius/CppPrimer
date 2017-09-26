#include <iostream>
using namespace std;

class Item_base{
public:
	Item_base(const std::string &book = "noname",
			double sales_price = 0.0): isbn(book), price(sales_price){ }
	std::string book() const { return isbn; }
	virtual double net_price(std::size_t n) const
				{return n * price;}
	virtual ~Item_base(){ }
private:
	std::string isbn;
protected:
	double price;
};

class Bulk_item: public Item_base{
public:
	Bulk_item(std::size_t m=0, double d=0): min_qty(m), discount(d){ }
	Bulk_item(const std::string &book, double sales_price, std::size_t m, double d)
		: Item_base(book, sales_price), min_qty(m), discount(d){ }
	~Bulk_item(){ }
	double net_price(std::size_t) const;
private:
	std::size_t min_qty;
	double discount;
};

double Bulk_item::net_price(size_t cnt) const
{
	if(cnt >= min_qty)
		return cnt * (1-discount)*price;
	else 
		return cnt*price;
}

int main(void)
{
	Bulk_item b(1, 0.1);
	cout << b.net_price(2) << endl;
	cout << b.book() << endl;

	Bulk_item B("BookName", 100.00, 2, 0.1);
	cout << B.net_price(3) << endl;
	cout << B.book() << endl;

}
