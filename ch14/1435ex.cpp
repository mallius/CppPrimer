#include <iostream>
#include <vector>
using namespace std;

class bet_cls{
public:
    bet_cls(string::size_type min, string::size_type max):lenmin(min),lenmax(max){ }
    int operator()(string &s)
    {
        return s.size() >= lenmin && s.size() <= lenmax;
    }
private:
    string::size_type lenmin;
    string::size_type lenmax;
};

int main(void)
{
    vector<string> svec {"wordcup","word","cup"};
    cout << count_if(svec.begin(), svec.end(), bet_cls(3,6)) << endl;
    return 0;
}