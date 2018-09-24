#include <iostream>
using namespace std;

class Item_base{
public:
	Item_base(const std::string &book = "", double sales_price = 0.0): isbn(book), price(sales_price){ }
	std::string book() const { return isbn; }
	virtual double net_price(std::size_t n) const {return n * price;}
	virtual ~Item_base(){ }
private:
	std::string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base {
public:
	Bulk_item(size_t min = 10, double dis = 0.8): min_qty(min), discount(dis), Item_base("", 1.0) {  }
	double net_price(std::size_t) const;

	//实现clone函数
	Bulk_item* clone() const { return new Bulk_item(*this); }

private:
	std::size_t min_qty;
	double discount;
};

double Bulk_item::net_price(size_t cnt) const 
{
	if(cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

int main(void)
{
	Bulk_item b(100, 0.9);
	cout << b.net_price(200) << endl;  //200 * (1-0.9) * 1.0 = 20
}
