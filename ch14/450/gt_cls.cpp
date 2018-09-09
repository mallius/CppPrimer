#include <iostream>
#include <vector>
using namespace std;

class GT_cls{
public:
    GT_cls(size_t val = 0) : bound(val){ }
    bool operator()(const string &s){ return s.size() >= bound; }
private:
    std::string::size_type bound;
};

int main(void)
{
    vector<string> svec {"wordcup", "word", "cup"};
    cout << count_if(svec.begin(), svec.end(), GT_cls(6)) << " words 6 characters or longer" << endl;
    cout << count_if(svec.begin(), svec.end(), GT_cls(3)) << " words 6 characters or longer" << endl;

    for(size_t i = 0; i != 11; ++i)
    {
        cout << count_if(svec.begin(), svec.end(), GT_cls(i)) << " words  " <<  i
             << " characters or longer" << endl;
    }
}