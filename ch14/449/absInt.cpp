#include <iostream>
using namespace std;

struct absInt{
    int operator() (int val){
        return val < 0 ? -val :val;
    }
};

int main(void)
{
    absInt absobj;
    unsigned int ui = absobj(1);
    cout << ui << endl;
}