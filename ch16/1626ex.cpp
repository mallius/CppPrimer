#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2, class T3> T1 sum(T2, T3)
{
	//T1 = T2 + T3;
	//return T1;
}




int main(void)
{
	double dobj1 = 1.1, dobj2 = 1.1;
	float fobj1 = 1.1, fobj2 = 1.1;
	char cobj1 = 'a', cobj2 = 'b';
	sum<double>(dobj1, dobj2);
	sum<double, double, double>(fobj1, fobj2);
	sum<int>(cobj1, cobj2);	
	sum<double, double, double>(fobj1, fobj2);
}
