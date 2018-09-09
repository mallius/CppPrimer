#include <iostream>
using namespace std;

class LongDouble {
public:
    LongDouble(double);
};

void calc(int) { cout << "calc(int)" << endl; }
void calc(LongDouble) { cout << "calc(LongDouble)" << endl; }

int main(void)
{
    double dval;
    calc(dval);   //calc(int)最佳转换
}