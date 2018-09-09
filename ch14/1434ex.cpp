#include <iostream>
#include <vector>
using namespace std;

class EQ_cls{
public:
    EQ_cls(int val = 0) : bound(val){ }
    bool operator()(int val){ return val == bound; }
private:
    int bound;
};

int main(void)
{
    vector<int> ivec{1, 2, 3, 4, 5};
    replace_if(ivec.begin(), ivec.end(), EQ_cls(3),6);
    for(auto &x : ivec){
        cout << x << endl;
    }
    return 0;
}