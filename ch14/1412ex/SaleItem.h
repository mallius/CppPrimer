
#ifndef SALESITEM_H
#define SALESITEM_H


#include <iostream>
#include <string>

class Sales_item {
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item&);
    friend Sales_item std::operator+=(const Sales_item&);
public:
    Sales_item(const std::string &book):
              isbn(book), units_sold(0), revenue(0.0) { }
    Sales_item(std::istream &is) { is >> *this; }
public:
    Sales_item operator+(const Sales_item&);

public:
    double avg_price() const;
    bool same_isbn(const Sales_item &rhs) const
        { return isbn == rhs.isbn; }
    Sales_item(): units_sold(0), revenue(0.0) { }
private:
    std::string isbn;
    unsigned units_sold;
    double revenue;

};

#endif
