#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(void)
{
    tuple<size_t, size_t, size_t> threeD = {1, 2, 3};
    tuple<string, vector<double>, int, list<int>> someVal("constants", {3.14, 2.718}, 42, {0, 1, 2, 3, 4, 5});
    auto item = make_tuple("0-999-78345-X", 3, 20.00);

    auto book = get<0>(item);
    auto cnt = get<1>(item);
    auto price = get<2>(item) / cnt;
    get<2>(item) *= 0.8;

    cout << book << endl;
    cout << cnt << endl;
    cout << price << endl;

    typedef decltype(item) trans;
    size_t sz = tuple_size<trans>::value;
    cout << sz << endl;

    tuple_element<1, trans>::type count = get<1>(item);
}