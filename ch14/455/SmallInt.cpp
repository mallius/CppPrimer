#include <iostream>
using namespace std;

class SmallInt {
public:
    SmallInt(int i = 0):val(i)
    {
       if(i < 0 || i > 255)
       {
           throw std::out_of_range("Bad SmallInt initializer");
       }
    }
    operator int() const {return val;}

private:
    std::size_t val;
};

class Integral{
public:
    Integral(int i = 0):val(i){ }
    operator SmallInt() const {return val % 256;}
private:
    std::size_t val;
};

int calc(int v)
{
    return v*2;
}

int main(void)
{
    SmallInt si(255);
    if(si){
        cout << "si <= 255" << endl;
        cout << si << endl;
    }

    int ival;
    si = 3.541;
    ival = static_cast<int>(si) + 3;
    cout << ival << endl;

    //test Integral
    Integral intVal(257);  //257%256==1
    SmallInt sint(intVal); //1
    int i = calc(sint);    //1*2
    cout << i << endl;

    return 0;
}