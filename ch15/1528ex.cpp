#include <iostream>
#include <vector>
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
	vector<Item_base> Item_baseVec;	
	Item_base b1;

	Item_base b2;
	Bulk_item bulk;
	b2 = bulk;

	Item_baseVec.push_back(b1);
	Item_baseVec.push_back(b2);
	double sum = 0;
	for(vector<Item_base>::iterator it = Item_baseVec.begin(); it != Item_baseVec.end(); ++it)
	{
		cout << (*it).net_price(1) << endl;
		sum += sum + (*it).net_price(1);
	}
	cout << "sum: " << sum << endl;
}

