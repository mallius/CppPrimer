#include <random>
#include <iostream>

using namespace std;
int main(void)
{
    default_random_engine e;
    for(size_t i = 0; i < 10; ++i)
    {
        cout << e() << " ";
    }

    uniform_int_distribution<unsigned> u(0, 9);
    for(size_t i = 0; i < 10; ++i)
    {
        cout << u(e) << " ";
    }
    cout << "e.min():" << e.min() << endl;
    cout << "e.max():" << e.max() << endl;
}