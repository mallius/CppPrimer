#include <functional>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    vector<int> ivec {1,2,3,4,5};
    vector<int>::iterator it = find_if(ivec.begin(), ivec.end(), bind2nd(greater<int>(),2));
    if(it != ivec.end()){
        cout << *it << endl;
    }
}
