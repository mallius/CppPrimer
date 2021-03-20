#include <iostream>
#include<string>
#include "DynOBJ.h"
using namespace std;

class Api 
{
public:
	virtual void test(string s) = 0;
protected:
	Api(){}
};


class ImpleOne :public Api 
{
public:
	void test(string s) 
	{
		cout << "现在是One在执行" << s;
	}
};

class ImpleTwo :public Api 
{
public:
	void test(string s) 
	{
		cout << "现在是Two在执行" << s;
	}
};


//class ImpleTwoHelper {
//public:
//	ImpleTwoHelper() {
//		CObjectFactory::registerClass("ImpleTwo", ImpleTwoHelper::createObjFunc);
//	}
//	static void* createObjFunc() {
//		return new ImpleTwo;
//	}
//};

REG_CLASS(ImpleTwo)

class AutoFactory
{
public:
	static Api* createApi() 
	{
		Api* pApi = nullptr;
		pApi = static_cast<Api*>(CObjectFactory::creatObject("ImpleTwo"));
		return pApi;
	}
};

int main() 
{
	Api* pApi = AutoFactory::createApi();
	pApi->test("哈哈完全不知道，里面的东西了");
	return 0;
}
