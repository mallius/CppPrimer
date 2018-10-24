#include <vector>
#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
    unique_ptr<double> p1;
    unique_ptr<int> p2{new int{42}};

    unique_ptr<string> ps1(new string("Stegosaurus"));
    unique_ptr<string> ps2(ps1.release());

    return 0;
}
