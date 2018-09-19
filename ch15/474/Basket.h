
#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>
#include <stdexcept>

// Item sold at an undiscounted price
// derived classes will define various discount strategies
class Item_base {

friend std::istream& operator>>(std::istream&, Item_base&);
friend std::ostream& operator<<(std::ostream&, const Item_base&);

public:
    virtual Item_base* clone() const { return new Item_base(*this); }

public:
    Item_base(const std::string &book = "", double sales_price = 0.0):
							isbn(book), price(sales_price) { }

    std::string book() const { return isbn; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Item_base() { } 
private:
    std::string isbn;   // identifier for the item

protected:
    double price;       // normal, undiscounted price
};

class Sales_item;

bool compare(const Sales_item &lhs, const Sales_item &rhs);

//折扣类
class Bulk_item : public Item_base {
public:
    std::pair<size_t, double> discount_policy() const { return std::make_pair(min_qty, discount); }
    // other members as before
    Bulk_item* clone() const { return new Bulk_item(*this); }
    Bulk_item(): min_qty(0), discount(0.0) { }
    Bulk_item(const std::string& book, double sales_price, std::size_t qty = 0, double disc_rate = 0.0):
										Item_base(book, sales_price), 
										min_qty(qty), discount(disc_rate) { }

    double net_price(std::size_t) const;
private:
    std::size_t min_qty;   // minimum purchase for discount to apply
    double discount;       // fractional discount to apply
};

// discount (a fraction off list) for only a specified number of copies, 
// additional copies sold at standard price
class Lim_item : public Item_base {
public:
    Lim_item(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0):
										Item_base(book, sales_price), 
										max_qty(qty), discount(disc_rate) { }

    double net_price(std::size_t) const;
private:
    std::size_t max_qty;   // maximum number sold at discount
    double discount;       // fractional discount to apply
public:
    Lim_item* clone() const { return new Lim_item(*this); }
    std::pair<size_t, double> discount_policy() const { return std::make_pair(max_qty, discount); }
};

// use counted handle class for the Item_base hierarchy 
class Sales_item {
friend class Basket;
public:
    // default constructor: unbound handle
    Sales_item(): p(0), use(new std::size_t(1)) { }

    // attaches a handle to a copy of the Item_base object
    Sales_item(const Item_base&); 

    // copy control members to manage the use count and pointers
    Sales_item(const Sales_item &i): 
                      p(i.p), use(i.use) { ++*use; }
    ~Sales_item() { decr_use(); }
    Sales_item& operator=(const Sales_item&);

    // member access operators
    const Item_base *operator->() const 
	{ 
		if (p) 
			return p; 
        else 
			throw std::logic_error("unbound Sales_item"); 
	}
    const Item_base &operator*() const 
	{ 
		if (p) 
			return *p; 
        else 
			throw std::logic_error("unbound Sales_item"); 
	}
private:
    Item_base *p;         // pointer to shared item
    std::size_t *use;     // pointer to shared use count

    // called by both destructor and assignment operator to free pointers
    void decr_use() 
    { 
		if (--*use == 0) 
		{ 
			delete p; 
			delete use; 
		} 
	}
};


// holds items being purchased
class Basket {
    // type of the comparison function used to order the multiset
    typedef bool (*Comp)(const Sales_item&, const Sales_item&);
public:
    // make it easier to type the type of our set
    typedef std::multiset<Sales_item, Comp> set_type;

    // typedefs modeled after corresponding container types
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;

    void display(std::ostream&) const;

    Basket(): items(compare) { }  // initialze the comparator 
    void add_item(const Sales_item &item) { items.insert(item); }
    size_type size(const Sales_item &i) const { return items.count(i); }
    double total() const;  // sum of net prices for all items in the basket
private:
    std::multiset<Sales_item, Comp> items;
};

inline
Sales_item::Sales_item(const Item_base &item):
            p(item.clone()), use(new std::size_t(1)) { }

// compare defines item ordering for the multiset in Basket
inline bool 
compare(const Sales_item &lhs, const Sales_item &rhs) 
{
    return lhs->book() < rhs->book(); 
} 
#endif

