
#include "Basket.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
	Sales_item item1(Item_base("123", 45));
	Sales_item item2(Bulk_item("345", 45, 3, .15));
	Sales_item item3(Bulk_item("678", 55, 5, .25));
	Sales_item item4(Lim_item("abc", 35, 2, .10));
	Sales_item item5(Item_base("def", 35));

	Basket sale;
	sale.add_item(item1);
cout << "added first item" << endl;
	sale.add_item(item1);
	sale.add_item(item1);
	sale.add_item(item1);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item2);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item3);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item4);
	sale.add_item(item5);
	sale.add_item(item5);
cout << "added last item" << endl;

	sale.display(cout);
	cout << sale.total() << endl;
{
	// arguments are the isbn, price, minimum quantity, and discount
	Bulk_item bulk("0-201-82470-1", 50, 5, .19);
	Basket sale;
	sale.add_item(Bulk_item("0-201-82470-1", 50, 5, .19));
	sale.add_item(Bulk_item("0-201-82470-1", 50, 5, .19));
	sale.add_item(Bulk_item("0-201-82470-1", 50, 5, .19));
	sale.add_item(Bulk_item("0-201-82470-1", 50, 5, .19));
	sale.add_item(Bulk_item("0-201-82470-1", 50, 5, .19));
	sale.add_item(Lim_item("0-201-54848-8", 35, 2, .10));
	sale.add_item(Lim_item("0-201-54848-8", 35, 2, .10));
	sale.add_item(Lim_item("0-201-54848-8", 35, 2, .10));
	double total = sale.total();
	cout << "Total Sale: " << total << endl;
}
}
