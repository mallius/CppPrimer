#include <iostream>
#include <string.h>
using namespace std;

namespace _nmsp3
{
	//目标函数
	void funcLast4(char* p)
	{
		//if (p != NULL)
		if (p != nullptr)
		{
			strncpy(p, "abc",3);
		}
	}

	//转发函数
	template <typename F, typename...T>
	void funcMiddle_Temp(F f, T&&... t)
	{
		f(std::forward<T>(t)...);
	}

}

int main()
{ 

	char* p = new char[100];
	memset(p, 0, 100);

	//_nmsp3::funcMiddle_Temp(_nmsp3::funcLast4, NULL);  
	//_nmsp3::funcLast4(NULL);
	_nmsp3::funcMiddle_Temp(_nmsp3::funcLast4, nullptr);

	return 0;
}

