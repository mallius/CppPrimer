#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> ivec{1000,2000,3000};
    cout << count_if(ivec.begin(), ivec.end(), not1(bind2nd(less_equal<int>(), 1024))) << endl;

    vector<string> svec {"aaa", "pooh", "bbb", "ccc"};
    cout << count_if(svec.begin(), svec.end(),bind1st(not_equal_to<string>(),"pooh")) << endl;

}