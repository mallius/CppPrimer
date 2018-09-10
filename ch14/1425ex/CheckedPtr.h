
#include <cstddef>

class CheckedPtr {
    friend bool operator==(const CheckedPtr& l, const CheckedPtr& r);
public:
    // no default constructor; CheckedPtrs must be bound to an object
    CheckedPtr(int *b, int *e): beg(b), end(e), curr(b) { }

    // dereference and increment operations

    // dereference operator
    int& operator*();
    const int& operator*() const;

    // increment and decrement
    CheckedPtr operator++(int);     // postfix operators
    CheckedPtr operator--(int);
    // other members as before

    CheckedPtr& operator++();       // prefix operators
    CheckedPtr& operator--();
    // other members as before

    int operator[](const size_t index);
    const int operator[](const size_t index) const;

    //bool operator==(const CheckedPtr& l, const CheckedPtr& r);
    //bool operator!=(const CheckedPtr& l, const CheckedPtr& r);

private:
    int* beg;    // pointer to beginning of the array
    int* end;    // one past the end of the array
    int* curr;   // current position within the array
};


inline
bool operator==(const CheckedPtr& l, const CheckedPtr& r)
{
    return l.beg== r.beg && l.end == r.end && l.curr == r.curr;  //访问私有，友元。
}

inline
bool operator!=(const CheckedPtr& l, const CheckedPtr& r)
{
    return !(l == r);
}
