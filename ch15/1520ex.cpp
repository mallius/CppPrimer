#include <iostream>
using namespace std;

class Item_base{
public:
	Item_base(const std::string &book = "", double sales_price = 0.0): isbn(book), price(sales_price){ cout << "Item_base()" << endl; }

	// 基类复制构造函数
	Item_base(const Item_base& base) 
	{ 
		isbn = base.isbn; 
		price = base.price; 
		cout << "base copy" << endl; 
	}	

	// 基类赋值操作符
	Item_base& operator=(Item_base& base)
	{
		if(this != &base) {
			isbn = base.isbn;
			price = base.price;
		}
		cout << "Item_base operator=" << endl;
		return *this;
	}

	std::string book() const { return isbn; }
	virtual double net_price(std::size_t n) const {return n * price;}
	virtual ~Item_base(){ cout << "~Item_base()" << endl; }
private:
	std::string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base {
public:
	Bulk_item(size_t min = 10, double dis = 0.8): min_qty(min), discount(dis), Item_base("", 1.0) {  cout << "Bulk_item()" << endl; }

	// 派生类复制构造
	Bulk_item(const Bulk_item& bulk) : Item_base(bulk)
	{ 
		min_qty = bulk.min_qty; 
		discount = bulk.discount; 
		cout << "Bulk_item copy" << endl; 
	}
	
	// 派生类赋值操作符
	Bulk_item& operator=(Bulk_item& bulk)
	{
		if(this != &bulk) {
			Item_base::operator=(bulk);
			min_qty = bulk.min_qty;
			discount = bulk.discount;
		}
		cout << "Bulk_item operator=" << endl;
		return *this;
	}

	double net_price(std::size_t) const;
	virtual ~Bulk_item() { cout << "~Bulk_item()" << endl; }
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
	//调用复制构造
	Bulk_item bulk(b);	
	
	Bulk_item Bulk; 
	//调用赋值操作符
	Bulk = b;
	return 0;
}
