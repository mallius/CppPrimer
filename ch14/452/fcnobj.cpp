
#include <functional>
using std::plus; using std::negate; using std::greater;

#include <iostream>
using std::cout; using std::endl;

#include <vector>
#include <algorithm>
using std::count_if; using std::bind2nd; using std::not1; using std::ptr_fun;
using std::less_equal; using std::vector;

#include <iostream>
using std::cin;

#include <string>
using std::string;

bool size_compare(string s, string::size_type sz)
{
    return s.size() >= sz;
}

int main() {

    cout << plus<int>()(3,4) << endl; // prints 7

    plus<int> intAdd;        // function object that can add two int values
    negate<int>  intNegate;  // function object that can negate an int value

    // uses intAdd::operator(int, int) to add 10 and 20
    int sum = intAdd(10, 20);        // sum = 30

    cout << sum << endl;

    // uses intNegate::operator(int) to generate -10 as second parameter
    // to intAdd::operator(int, int)
    sum = intAdd(10, intNegate(10));  // sum = 0

    cout << sum << endl;

    int arry[] = {0,1,2,3,4,5,16,17,18,19};

    vector<int> vec(arry, arry + 10);

    cout <<
    count_if(vec.begin(), vec.end(),
             bind2nd(less_equal<int>(), 10));
    cout << endl;

    cout <<
    count_if(vec.begin(), vec.end(),
             not1(bind2nd(less_equal<int>(), 10)));
    cout << endl;

    vector<string> svec{"bbb","aaa","ccc"};
    sort(svec.begin(),svec.end(),greater<string>());
    for(auto &x : svec){
        cout << x << endl;
    }

    return 0;
}
