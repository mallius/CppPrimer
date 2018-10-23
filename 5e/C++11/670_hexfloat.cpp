#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
    std::cout << "hexfloat: " << std::hexfloat << 100 * sqrt(2.0) << std::endl;
    std::cout << "hexfloat: " << std::hexfloat << 2.0 << std::endl;
    return 0;
}