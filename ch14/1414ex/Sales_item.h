
#ifndef SALESITEM_H
#define SALESITEM_H


#include <iostream>
#include <string>

class Sales_item {
    friend bool operator==(const Sales_item&, const Sales_item&);
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item&);
// other members as before
public:
    // added constructors to initialize from a string or an istream
    Sales_item(const std::string &book):
              isbn(book), units_sold(0), revenue(0.0) { }
    Sales_item(std::istream &is) { is >> *this; }
public:
    Sales_item& operator+=(const Sales_item&);
    Sales_item& operator=(const Sales_item&);

public:
    // operations on Sales_item objects
    double avg_price() const;
    bool same_isbn(const Sales_item &rhs) const { return isbn == rhs.isbn; }
    void set_isbn(const std::string& s) { isbn = s; }
    std::string& get_isbn(void) { return isbn; }
    // default constructor needed to initialize members of built-in type
    Sales_item(): units_sold(0), revenue(0.0) { }
// private members as before
private:
    std::string isbn;
    unsigned units_sold;
    double revenue;

};


// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool 
operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue &&
	   lhs.same_isbn(rhs);
}

inline bool 
operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

#endif
