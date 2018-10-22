#include <iostream>

class SmallInt {
public:
    SmallInt(int i = 0): val(i)
    {
        if(i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }
    explicit operator int() const { return val; }
private:
    std::size_t val;
};
int main(void)
{
    SmallInt si = 3;
    // si + 3;
    static_cast<int>(si) + 3;
    return 0;
}