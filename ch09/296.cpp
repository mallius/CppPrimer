#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	string name("AnnaBelle");
	string::size_type pos1 = name.find("Anna");
	cout << pos1 << endl;

	string lowcase("annabella");
	string::size_type pos2 = lowcase.find("Anna");
	cout << pos2 << endl;

	string numerics("0123456789");
	string na("r2d2e3");
	string::size_type pos = na.find_first_of(numerics);  //r2d2中找到第一个数字
	cout << "found number at index: " << pos << " element is " << na[pos] << endl;

	++pos;
	//在上一次的基础上继续查找数字
	while((pos = na.find_first_of(numerics, pos)) != string::npos) 
	{
		cout << "found number at index: " << pos << " element is " << na[pos] << endl;
		++pos;
	}
	return 0;
}
