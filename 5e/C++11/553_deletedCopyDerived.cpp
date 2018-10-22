#include <iostream>

class B {
public:
    B() = default;
    B(const B&) = delete;
};

class D: public B {

};

int main(void)
{
    D d;
    // D d2(d);
    // D d3(std::move(d));
}