#include <iostream>
using namespace std;

struct thrJudge{
    int operator() (int a, int b, int c){
        if(a == b)
            return b;
        return c;
    }
};

int main(void)
{
    thrJudge t;
    int ret = t(1,2,3);
    cout << ret << endl;
}