#include <iostream>
using namespace std;

class Item_base{
public:
	Item_base(const std::string &book = "", double sales_price = 0.0): isbn(book), price(sales_price) { }

	// 基类复制构造函数
	Item_base(const Item_base& base) 
	{ 
		isbn = base.isbn; 
		price = base.price; 
	}	

	// 基类赋值操作符
	Item_base& operator=(Item_base& base)
	{
		if(this != &base) {
			isbn = base.isbn;
			price = base.price;
		}
		return *this;
	}

	std::string book() const { return isbn; }
	virtual double net_price(std::size_t n) const {return n * price;}
	virtual ~Item_base() {  }
private:
	std::string isbn;
protected:
	double price;
};

class Disc_item : public Item_base {
public:
	Disc_item(size_t min = 10, double dis = 0.8): min_qty(min), discount(dis), Item_base("", 1.0) {  }

	// 派生类复制构造
	Disc_item(const Disc_item& disc) : Item_base(disc)
	{ 
		min_qty = disc.min_qty; 
		discount = disc.discount; 
	}
	
	// 派生类赋值操作符
	Disc_item& operator=(Disc_item& disc)
	{
		if(this != &disc) {
			Item_base::operator=(disc);
			min_qty = disc.min_qty;
			discount = disc.discount;
		}
		return *this;
	}

	double net_price(std::size_t) const;
	virtual ~Disc_item() {  }
private:
	std::size_t min_qty;
	double discount;
};

double Disc_item::net_price(size_t cnt) const 
{
	if(cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

int main(void)
{
	Disc_item d(100, 0.9);
	cout << d.net_price(200) << endl;  //200 * (1-0.9) * 1.0 = 20
	//调用复制构造
	Disc_item disc(d);	
	
	Disc_item Disc; 
	//调用赋值操作符
	Disc= d;
	return 0;
}
