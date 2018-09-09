
#include <cstddef>

class CheckedPtr {
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
private:
    int* beg;    // pointer to beginning of the array
    int* end;    // one past the end of the array
    int* curr;   // current position within the array
};
