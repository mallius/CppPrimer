
#include "CheckedPtr.h"
#include <iostream>
using std::cerr; 
#include <stdexcept>
using std::out_of_range;

int& CheckedPtr::operator*() 
{
    if (curr == end)
        throw out_of_range("dereference past the end");
    return *curr; 
}

const int& CheckedPtr::operator*() const
{
    if (curr == end)
        throw out_of_range("dereference past the end");
     return *curr; 
}


// postfix: increment/decrement object but return unchanged value
CheckedPtr CheckedPtr::operator++(int)
{
    // no check needed here, the call to prefix increment will do the check
    CheckedPtr ret(*this);   // save current value
    ++*this;                 // advance one element, checking the increment
    return ret;              // return saved state
}

CheckedPtr CheckedPtr::operator--(int)
{
    // no check needed here, the call to prefix decrement will do the check
    CheckedPtr ret(*this);  // save current value
    --*this;                // move backward one element and check
    return ret;             // return saved state
}

// prefix: return reference to incremented/decremented object
CheckedPtr& CheckedPtr::operator++()
{
    if (curr == end) 
        throw out_of_range
              ("increment past the end of CheckedPtr");

    ++curr;                // advance current state
    return *this;
}

CheckedPtr& CheckedPtr::operator--()
{
    if (curr == beg) 
        throw out_of_range
          ("decrement past the beginning of CheckedPtr");

    --curr;              // move current state back one element
    return *this;
}

