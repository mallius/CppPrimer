//桥接模式
#include <iostream>
using namespace std;

//接口
class IOS {
public:
	IOS(){}
	virtual ~IOS() {}
	virtual void run() = 0;
};

class CWindows :public IOS {
public:
	virtual void run() {
		cout << "Windows 正在运行" << endl;
	}
};

class CLinux :public IOS {
public:
	virtual void run() {
		cout << "Linux 正在运行" << endl;
	}
};

//接口
class IComputer {
public:
	virtual void Install(IOS *pOS) = 0;
};

class CLenvo :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Lenvo正在安装操作系统" << endl;
		pOS->run();
	}
};

class CDell :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Dell正在安装操作系统" << endl;
		pOS->run();
	}
};

class CAcer:public IComputer
{
public:
public:
	virtual void Install(IOS *pOS) {
		cout << "Acer正在安装操作系统" << endl;
		pOS->run();
	}

private:

};


int main(void) {
	IOS* pWindows = new CWindows;
	IOS* pLinux = new CLinux;

	IComputer* pLenvo = new CLenvo;
	pLenvo->Install(pWindows);
	pLenvo->Install(pLinux);

	return 0;
}

