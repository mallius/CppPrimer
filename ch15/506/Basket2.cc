
#include "Basket2.h"
#include <algorithm>
using std::multiset; using std::map; using std::pair; using std::size_t;
using std::string; using std::ostream; using std::endl; using std::min;
using std::cout;

// debugging routine to check contents in a Basket
void Basket::display(ostream &os) const
{
    os << "Basket size: " << items.size() << endl;

    // print each distinct isbn in the Basket along with
    // count of how many copies are ordered and what their price will be
    // upper_bound returns an iterator to the next item in the set
    for (const_iter next_item = items.begin();
                  next_item != items.end();
                  next_item = items.upper_bound(*next_item))
    {
        // we know there's at least one element with this key in the Basket
        os << (*next_item)->book() << " occurs " 
           << items.count(*next_item) << " times" 
           << " for a price of " 
           << (*next_item)->net_price(items.count(*next_item)) 
           << endl;
    }
}

void print_total(ostream &, const Item_base&, size_t);

// calculate and print price for given number of copies, applying any discounts 
void print_total(ostream &os, 
                 const Item_base &item, size_t n)
{
    os << "ISBN: " << item.book() // calls Item_base::book
       << "\tnumber sold: " << n << "\ttotal price: "
       // virtual call: which version of net_price to call is resolved at run time
       << item.net_price(n) << endl;
}

double Basket::total() const
{
    double sum = 0.0;    // holds the running total 


    for (const_iter iter = items.begin(); 
                    iter != items.end();
                    iter = items.upper_bound(*iter))
    {
        // we know there's at least one element with this key in the Basket
        print_total(cout, *(iter->p), items.count(*iter));
        // virtual call to net_price applies appropriate discounts, if any
        sum += (*iter)->net_price(items.count(*iter));
    }
    return sum;
}

// use-counted assignment operator; use is a pointer to a shared use count
Sales_item&
Sales_item::operator=(const Sales_item &rhs)
{
    ++*rhs.use;
    decr_use();
    p = rhs.p;
    use = rhs.use;
    return *this;
}

// if specified number of items are purchased, use discounted price 
double Bulk_item::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// use discounted price for up to a specified number of items
// additional items priced at normal, undiscounted price
double Lim_item::net_price(size_t cnt) const
{
    size_t discounted = min(cnt, quantity);
    size_t undiscounted = cnt - discounted;
    return discounted * (1 - discount) * price 
           + undiscounted * price;
}

