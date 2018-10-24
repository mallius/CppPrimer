#include <memory>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(void)
{
    shared_ptr<string> p1;
    shared_ptr<list<int>> p2;
    if(p1 && p1->empty())
        *p1 = "hi";

    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    shared_ptr<int> p5 = make_shared<int>();
    auto p6 = make_shared<vector<string>>();

    auto p = make_shared<int>(42);
    auto q(p);
    auto r = make_shared<int>(42);
    r = q;

    return 0;
}