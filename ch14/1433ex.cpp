#include <iostream>
#include <vector>
using namespace std;

class GT_cls{
public:
    GT_cls(int val = 0) : bound(val){ }
    bool operator()(int val){ return val > bound; }
private:
    int bound;
};

int main(void)
{
    vector<int> ivec{1,2,3,10,6,7};
    auto it = find_if(ivec.begin(), ivec.end(), GT_cls(3));
    if(it != ivec.end())
        cout << *it << endl;
}