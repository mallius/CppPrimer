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

	// 纯虚函数，该类已经为抽象基类，无法创建对象。只能用于继承
	double net_price(std::size_t cnt) const = 0;

	virtual ~Disc_item() {  }
private:
	std::size_t min_qty;
	double discount;
};


int main(void)
{
	// Disc_item d;
	return 0;
}
