
#include "SalesItem.h"
#include <iostream>
using std::istream; using std::ostream;

// assumes that both objects refer to the same isbn
Sales_item Sales_item::operator+(const Sales_item& rhs)
{
    units_sold += rhs.units_sold; 
    revenue += rhs.revenue; 
    return *this;
}


Sales_item operator+=(const Sales_item& s)
{

}

istream& 
operator>>(istream& in, Sales_item& s)
{
    double price;
    in >> s.isbn >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else 
        s = Sales_item();  // input failed: reset object to default state
    return in;
}

ostream& 
operator<<(ostream& out, const Sales_item& s)
{
    out << s.isbn << "\t" << s.units_sold << "\t" 
        << s.revenue << "\t" <<  s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold) 
        return revenue/units_sold; 
    else 
        return 0;
}

int main(void)
{

}
