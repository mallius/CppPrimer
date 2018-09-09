#include <iostream>
#include <vector>
using namespace std;

class thr_cls{
public:
    thr_cls(string::size_type min, string::size_type max, string::size_type big)
            :lenmin(min),lenmax(max), lenbigest(big){ }
    int operator()(string &s)
    {
        return (s.size() >= lenmin && s.size() <= lenmax) || s.size() > lenbigest;
    }
private:
    string::size_type lenmin;
    string::size_type lenmax;
    string::size_type lenbigest;
};

int main(void)
{
    vector<string> svec {"wordcup","word","cup","cuuuuuuuuuuuup"};
    cout << count_if(svec.begin(), svec.end(), thr_cls(3,6,10)) << endl;
    return 0;
}