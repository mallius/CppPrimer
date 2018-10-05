// Item_base类
#ifndef _ITEM_BASE_H_
#define _ITEM_BASE_H_

#include <iostream>
#include <string>

class Item_base {
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

#endif
