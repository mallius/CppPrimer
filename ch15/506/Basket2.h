
#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>



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
    std::string isbn;   
protected:
    double price;       

};


//抽象基类
class Disc_item : public Item_base {
public:
    std::pair<size_t, double> discount_policy() const { return std::make_pair(quantity, discount); }

	//纯虚函数，抽象类
    double net_price(std::size_t) const = 0;
    Disc_item(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0):
										Item_base(book, sales_price), 
										quantity(qty), discount(disc_rate) { }
protected:
    std::size_t quantity;  
    double discount;       
};



class Bulk_item : public Disc_item {
public:
    std::pair<size_t, double> discount_policy() const { return std::make_pair(quantity, discount); }

    Bulk_item* clone() const { return new Bulk_item(*this); }

    Bulk_item(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0):
										Disc_item(book, sales_price, qty, disc_rate) { }

	// 实现这个纯虚函数
    double net_price(std::size_t) const;
};



class Lim_item : public Disc_item {
public:
    Lim_item(const std::string& book = "", double sales_price = 0.0, std::size_t qty = 0, double disc_rate = 0.0):
										Disc_item(book, sales_price, qty, disc_rate) { }

	// 实现这个纯虚函数
    double net_price(std::size_t) const;
    Lim_item* clone() const { return new Lim_item(*this); }
    std::pair<size_t, double> discount_policy() const { return std::make_pair(quantity, discount); }
};


//句柄
class Sales_item {
    friend class Basket;   
public:
    Sales_item(): p(0), use(new std::size_t(1)) { }

    Sales_item(const Item_base&); 

    Sales_item(const Sales_item &i): p(i.p), use(i.use) { ++*use; }

    ~Sales_item() { decr_use(); }

    Sales_item& operator=(const Sales_item&);

    const Item_base *operator->() const { return p; }
    const Item_base &operator*() const { return *p; }
private:
    Item_base *p;         
    std::size_t *use;     


    void decr_use() 
         { if (--*use == 0) {delete p; delete use;} }
};

bool compare(const Sales_item &, const Sales_item &);

class Basket {

    typedef bool (*Comp)(const Sales_item&, const Sales_item&);
    std::multiset<Sales_item, Comp> items;
public:

    typedef std::multiset<Sales_item, Comp>::size_type size_type;
    typedef std::multiset<Sales_item, Comp>::const_iterator const_iter;

    Basket(): items(compare) { }  // initialze the comparator
    void display(std::ostream&) const;

    void add_item(const Sales_item &item) 
                        { items.insert(item); }
    size_type size(const Sales_item &i) const
                         { return items.count(i); }
    double total() const;  // sum of net prices for all items in the basket
};

inline
Sales_item::Sales_item(const Item_base &item):
            p(item.clone()), use(new std::size_t(1)) { }


inline bool 
compare(const Sales_item &lhs, const Sales_item &rhs) 
{
    return lhs->book() < rhs->book();
} 

#endif
